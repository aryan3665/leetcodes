// User function Template for C++

class Solution {
  public:
    int r, c;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    bool valid(int i, int j) { return (i >= 0 && i < r && j >= 0 & j < c); }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        r=mat.size();
        c=mat[0].size();
        //apply bfs in border and replace o with t
        queue<pair<int,int>>q;
        //first row
        for(int j=0;j<c;j++){
            if(mat[0][j]=='O'){
                q.push({0,j});
                mat[0][j]='T';
            }
        }
        //first coloumn
        for(int j=0;j<r;j++){
             if(mat[j][0]=='O'){
                  q.push({j,0});
                mat[j][0]='T';
            }
        }
        //last row
        
          for(int j=1;j<c;j++){
             if(mat[r-1][j]=='O'){
                  q.push({r-1,j});
                mat[r-1][j]='T';
            }
        }
        
        //last coloumn
         for(int j=1;j<r;j++){
             if(mat[j][c-1]=='O'){
                  q.push({j,c-1});
                mat[j][c-1]='T';
            }
        }
        
         while (!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        
                                for (int k = 0; k < 4; k++) {
                            if (valid(new_i + row[k], new_j + col[k]) &&
                                mat[new_i + row[k]][new_j + col[k]] == 'O') {
                                mat[new_i + row[k]][new_j + col[k]] = 'T';
                                q.push({new_i + row[k], new_j + col[k]});
                                }
                                }
         }
         
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 if(mat[i][j]=='O'){
                     mat[i][j]='X';
                 }
                 else if(mat[i][j]=='T'){
                     mat[i][j]='O';
                 }
             }
         }
         return mat;
    }
};