class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
       
        int n = grid.size();
        long long N=n*n;

    long long gridsum=0;
    long long gridsqsum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gridsum+=grid[i][j];
            gridsqsum+=grid[i][j]*grid[i][j];
        }
    }
    long long exsum=(N*(N+1))/2;
    long long exsqsum=(N*(N+1)*(2*N+1))/6;
    int sqdiff=gridsqsum-exsqsum;
    int sumdiff=gridsum-exsum;
    int a=(sqdiff/sumdiff+sumdiff)/2;
    int b=(sqdiff/sumdiff-sumdiff)/2;
    ans[0]=a;
    ans[1]=b;


        return ans;
    }
};
