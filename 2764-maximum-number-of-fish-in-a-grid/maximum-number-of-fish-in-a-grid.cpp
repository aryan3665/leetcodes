class Solution {
public:
int r,c;
int ans=INT_MIN;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool issafe(int i,int j){
    return (i>=0&&i<r&&j>=0&&j<c);
}
void dfs(vector<vector<int>>& grid,int i,int j,int &tempscore){
    tempscore+=grid[i][j];
    grid[i][j]=0;
    for(int k=0;k<4;k++){
        int nx=i+row[k];
        int ny=j+col[k];
        if(issafe(nx,ny)&&grid[nx][ny]>0){
            dfs(grid,nx,ny,tempscore);
        }
    }
}
    int findMaxFish(vector<vector<int>>& grid) {
      
         r=grid.size();
        c=grid[0].size();
       
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                   int tempscore=0;
                if(grid[i][j]>0){
                 
                    dfs(grid,i,j,tempscore);
                    ans=max(ans,tempscore);
                  
                }
            }
        }
               
            
        return ans==INT_MIN?0:ans;
    }
};