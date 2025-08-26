class Solution {
public:
    int N, M;
    const int MOD = 1e9 + 7;

    // dp[i][p][g] = number of schemes using crimes from i..end
    // with profit so far = p (capped at M), and g members used.
    int dp[101][101][101]; // constraints allow this (n, group.size, minProfit <= 100)

    int f(int i, int profits, int person, vector<int>& group, vector<int>& profit) {
        if (person > N) return 0;  // invalid (too many people)
        if (i == profit.size()) {
            return profits >= M ? 1 : 0; // valid if profit >= minProfit
        }

        if (dp[i][profits][person] != -1) return dp[i][profits][person];

        // Option 1: skip this crime
        long long notpic = f(i+1, profits, person, group, profit);

        // Option 2: pick this crime
        int newProfit = min(M, profits + profit[i]); // cap at minProfit
        long long pic = f(i+1, newProfit, person + group[i], group, profit);

        return dp[i][profits][person] = (pic + notpic) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        M = minProfit;

        memset(dp, -1, sizeof(dp));

        return f(0, 0, 0, group, profit);
    }
};
