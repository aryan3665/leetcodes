class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            set<char> s;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.' && s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            set<char> s;
            for (int j = 0; j < n; j++) {
                if (board[j][i] != '.' && s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                set<char> s;
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        int k = i * 3 + a, l = j * 3 + b;
                        if (board[k][l] != '.' && s.count(board[k][l])) return false;
                        s.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};