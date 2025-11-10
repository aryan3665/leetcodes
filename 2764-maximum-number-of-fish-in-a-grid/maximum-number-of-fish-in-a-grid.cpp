class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool issafe(int i,int j){
    return (i>=0&&i<r&&j>=0&&j<c);
}
    int findMaxFish(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
         r=grid.size();
        c=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    q.push({i,j});
                }
                 int tempscore=0;
                while(!q.empty()){
                   
                    auto it=q.front();
                    q.pop();
                    int i_=it.first;
                    int j_=it.second;
                    tempscore+=grid[i_][j_];
                    grid[i_][j_]=0;
                    for(int k=0;k<4;k++){
                        int nx=i_+row[k];
                        int ny=j_+col[k];
                        if(issafe(nx,ny)&&grid[nx][ny]>0){
                            q.push({nx,ny});
                        }

                    }

                }
                ans=max(ans,tempscore);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};