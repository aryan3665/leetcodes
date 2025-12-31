class Solution {
public:
int ROW;
int COL;
vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};

bool dfs (vector<vector<int>>&grid,int i,int j){
    if(i<0||i>=ROW||j<0||j>=COL||grid[i][j]==1){
        return false;
    }

    if(i==ROW-1)return true;

    grid[i][j]=1;//mark visited
    for(auto&dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(dfs(grid,new_i,new_j))return true;
    }

    return false;

}
bool canreach(vector<vector<int>>& cells,int mid){
    //yaha 1st row ke allowed cell se dfs marenge and check ki last row me pahuch sakte hain ya nhi 
    vector<vector<int>>grid(ROW,vector<int>(COL));
    for(int i=0;i<=mid;i++){
        int x=cells[i][0]-1;
        int y=cells[i][1]-1;
        grid[x][y]=1;
    }

    for(int j=0;j<COL;j++){
        if(grid[0][j]==0&& dfs(grid,0,j))return true;
    }


    return false;
}

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;
        int l=0;
        int r=cells.size();
        int lastday=0;
        //binary search on given cells array
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canreach(cells,mid)){
                lastday=mid+1;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return lastday;
    }
};