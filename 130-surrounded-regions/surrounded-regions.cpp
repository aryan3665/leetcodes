class Solution {
public:
    int r;
    int c;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    bool valid(int i, int j) { return (i >= 0 && i < r && j >= 0 & j < c); }
    void solve(vector<vector<char>>& board) {

        r = board.size();
        c = board[0].size();
        queue<pair<int, int>> q;
        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = 'T';
            }
        }

        // first coloumn
        for (int j = 0; j < r; j++) {
            if (board[j][0] == 'O') {
                q.push({j, 0});
                board[j][0] = 'T';
            }
        }
        // last row

        for (int j = 1; j < c; j++) {
            if (board[r - 1][j] == 'O') {
                q.push({r - 1, j});
                board[r - 1][j] = 'T';
            }
        }

        // last coloumn
        for (int j = 1; j < r; j++) {
            if (board[j][c - 1] == 'O') {
                q.push({j, c - 1});
                board[j][c - 1] = 'T';
            }
        }

        while (!q.empty()) {
            int new_i = q.front().first;
            int new_j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                if (valid(new_i + row[k], new_j + col[k]) &&
                    board[new_i + row[k]][new_j + col[k]] == 'O') {
                    board[new_i + row[k]][new_j + col[k]] = 'T';
                    q.push({new_i + row[k], new_j + col[k]});
                }
            }
        }
        for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 if(board[i][j]=='O'){
                     board[i][j]='X';
                 }
                 else if(board[i][j]=='T'){
                     board[i][j]='O';
                 }
             }
         }
         
    }

};