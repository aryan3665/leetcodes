
class Solution {
public:

    int dp[105][105];

    bool f(string& s, int open, int i) {

        // Invalid state
        if (open < 0) {
            return false;
        }

        // End of string
        if (i == s.size()) {
            return open == 0;
        }

        // Already calculated
        if (dp[i][open] != -1) {
            return dp[i][open];
        }

        bool ans = false;

        if (s[i] == '(') {

            ans = f(s, open + 1, i + 1);

        }
        else if (s[i] == ')') {

            ans = f(s, open - 1, i + 1);

        }
        else { // '*'

            // '*' -> '('
            bool o1 = f(s, open + 1, i + 1);

            // '*' -> empty
            bool o2 = f(s, open, i + 1);

            // '*' -> ')'
            bool o3 = f(s, open - 1, i + 1);

            ans = o1 || o2 || o3;
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {

        memset(dp, -1, sizeof(dp));

        return f(s, 0, 0);
    }
};
