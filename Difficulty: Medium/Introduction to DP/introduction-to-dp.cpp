class Solution {
  private:
    const long long mod = 1e9 + 7;

  private:
    long long int memo(int n, vector<long long> &dp){
        if(n <= 1) return n;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (memo(n-1, dp) + memo(n-2, dp))%mod;
    }
    
    
  public:
    long long int topDown(int n) {
        vector<long long int> dp(n+1, -1);
        return memo(n, dp);
    }
    
    long long int bottomUp(int n) {
        // tabulation
        if(n <= 1) return n;
        
        long long prev = 1, prev2 = 0, curi;
        
        for(int i = 0; i<n-1; i++){
            curi = (prev + prev2) % mod;
            prev2 = prev;
            prev = curi;
        }
        
        return prev;
    }
};
