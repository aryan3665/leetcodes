class Solution {
public:
    int n, m;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool isvalid(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<pair<int,int>, int>> q;

        // Start BFS from all 0 cells
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int step = q.front().second;
                q.pop();
                
                dist[x][y] = step;

                for(int k=0; k<4; k++){
                    int nx = x + row[k];
                    int ny = y + col[k];
                    if(isvalid(nx, ny) && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({{nx, ny}, step + 1});
                    }
                }
            }
        }

        return dist;
    }
};
