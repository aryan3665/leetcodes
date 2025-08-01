class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int total=0;
        for(auto x:arr){
            total+=x;
        }
int sum=total;
    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

    // Base case: sum = 0 is always possible
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // First element
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    // Fill the table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            bool nt = dp[i - 1][j]; // not take
            bool t = false;
            if (j >= arr[i])
                t = dp[i - 1][j - arr[i]]; // take

            dp[i][j] = nt || t;
        }
    }


    int mini=1e9;
    for(int s1=0;s1<=total/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs((total-s1)-s1));
        }
    }

    return mini;
    
    }
};
