class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jd, int n, int idx, int d) {
        // basec case id d==1 to remaining sabhi task ko usi din karna hoga
        if (d == 1) {
            int maxd = jd[idx];
            for (int i = idx; i < n; i++) {
                maxd = max(maxd, jd[i]);
            }
            return maxd;
        }
        if(t[idx][d]!=-1)return t[idx][d];
        int maxd = INT_MIN;
        int result;
        int final = INT_MAX;

        for (int i = idx; i <= n - d; i++) {
            maxd = max(maxd, jd[i]);
            result = maxd + solve(jd,n,i + 1,d-1);
            final = min(final, result);
        }
        return t[idx][d]=final;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();

        if (n < d)
            return -1;
            memset(t,-1,sizeof(t));
        return solve(jd, n, 0, d);
    }
};