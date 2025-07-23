// User function Template for C++

class Solution {
  public:
  bool dfs(vector<vector<int>>& matrix,int r,int c,int &n,int &m){
      if(r<0||c<0||r>=n||c>=m)return false;
      
      if(matrix[r][c]==0){
          return true;
      }
      matrix[r][c]=0;
      
      bool _left=dfs(matrix,r,c-1,n,m);
      bool _right=dfs(matrix,r,c+1,n,m);
      bool _up=dfs(matrix,r-1,c,n,m);
      bool _down=dfs(matrix,r+1,c,n,m);
      return(_left&&_right&&_up&&_down);
  }
  
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(dfs(matrix,i,j,n,m)==true)c++;
                }
            }
        }
        
        return c;
        
        
    }
};