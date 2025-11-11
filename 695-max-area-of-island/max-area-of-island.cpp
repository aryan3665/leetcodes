class Solution {
public:
    int r, c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
    bool issafe(int i, int j) { return (i >= 0 && j >= 0 && i < r && j < c); }
    void dfs(int i,int j,vector<vector<int>>&grid,int &tempcount){
        grid[i][j]=0;
        tempcount++;
        for(int k=0;k<4;k++){
            int nx=i+row[k];
            int ny=j+col[k];
            if(issafe(nx,ny)&&grid[nx][ny]==1){
                dfs(nx,ny,grid,tempcount);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int result = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int tempcount = 0;
                if (grid[i][j] == 1) {
                    dfs(i,j,grid,tempcount);
                    result = max(result, tempcount);

                } 
              
            }
        }
        return result;
    }
};