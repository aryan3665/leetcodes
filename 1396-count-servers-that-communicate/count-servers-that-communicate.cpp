class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //brute force
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool flag=0;
                if(grid[i][j]==1){
                    for(int k=0;k<m;k++){
                        if(grid[i][k]==1&(k!=j)){
                            
                            flag=1;
                            break;}


                    }



                    for(int l=0;l<n;l++){
                        if(grid[l][j]==1 &(l!=i)){
                            flag=1;
                            break;
                        }
                    }

                    if(flag==1)ans+=1;
                }
            }
        }


        return ans;
    }
};