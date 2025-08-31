#include <vector>
#include <array>
#include <cstdint>

using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // masks: bit k (0..8) means digit (k+1) is USED
        std::array<int, 9> row{}, col{}, box{};

        empties.clear();
        // initialize masks and collect empties
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    empties.push_back({r, c});
                } else {
                    int d = board[r][c] - '1';
                    int b = boxId(r, c);
                    row[r] |= (1 << d);
                    col[c] |= (1 << d);
                    box[b] |= (1 << d);
                }
            }
        }
        dfs(board, row, col, box);
    }

private:
    struct Cell { int r, c; };
    vector<Cell> empties;

    static inline int boxId(int r, int c) { return (r/3)*3 + (c/3); }

    // return index in 'empties' of the cell with minimum remaining values (MRV)
    int pick_cell(const vector<vector<char>>& b,
                  const std::array<int,9>& row,
                  const std::array<int,9>& col,
                  const std::array<int,9>& box) {
        int best_idx = -1;
        int best_count = 10;

        for (int i = 0; i < (int)empties.size(); ++i) {
            const auto& [r,c] = empties[i];
            if (b[r][c] != '.') continue; // already filled in deeper recursion

            int used = row[r] | col[c] | box[boxId(r,c)];
            int avail_mask = (~used) & 0x1FF; // 9 bits
            int cnt = __builtin_popcount(avail_mask);
            if (cnt < best_count) {
                best_count = cnt;
                best_idx = i;
                if (cnt == 1) break; // cannot do better
            }
        }
        return best_idx;
    }

    bool dfs(vector<vector<char>>& b,
             std::array<int,9>& row,
             std::array<int,9>& col,
             std::array<int,9>& box) {
        // check if solved: no dots remain
        // (cheap check: we know we place exactly once per recursion; scan for any dot)
        bool done = true;
        for (const auto& cell : empties) {
            if (b[cell.r][cell.c] == '.') { done = false; break; }
        }
        if (done) return true;

        int idx = pick_cell(b, row, col, box);
        auto [r, c] = empties[idx];

        int used = row[r] | col[c] | box[boxId(r,c)];
        int avail = (~used) & 0x1FF; // bits for candidates 1..9

        // try candidates (iterate set bits)
        while (avail) {
            int bit = avail & -avail;       // lowest set bit
            avail -= bit;                   // clear it
            int d = __builtin_ctz(bit);     // 0..8 for digit d+1

            // place
            b[r][c] = char('1' + d);
            row[r] |= bit;
            col[c] |= bit;
            box[boxId(r,c)] |= bit;

            if (dfs(b, row, col, box)) return true;

            // undo
            b[r][c] = '.';
            row[r] &= ~bit;
            col[c] &= ~bit;
            box[boxId(r,c)] &= ~bit;
        }
        return false; // backtrack
    }
};