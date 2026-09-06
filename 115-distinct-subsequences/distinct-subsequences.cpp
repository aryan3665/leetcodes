class Solution { 
public: 
    int f(string &s, string &t, int i, int j, int n, int m, 
          vector<vector<int>> &dp) {

        // t complete ho gaya
        if (j == m)
            return 1;

        // s complete ho gaya but t abhi baaki hai
        if (i == n)
            return 0;

        // already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int yes = 0;
        int no = 0;

        // characters match
        if (s[i] == t[j]) {

            // s[i] ko le liya
            yes = f(s, t, i + 1, j + 1, n, m, dp);

            // s[i] ko nahi liya
            no = f(s, t, i + 1, j, n, m, dp);
        }
        else {

            // match nahi hua, so s[i] ko skip karo
            no = f(s, t, i + 1, j, n, m, dp);
        }

        return dp[i][j] = yes + no;
    }

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(s, t, 0, 0, n, m, dp);
    }
};