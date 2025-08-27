class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.size();

        // Optimization: if sorted chars don't match, can't be scramble
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return memo[key] = false;

        for (int i = 1; i < n; i++) {
            // Case 1: no swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: swapped
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};
