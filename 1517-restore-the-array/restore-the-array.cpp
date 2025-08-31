class Solution {
public:
    long long MOD = 1e9+7;

    int f(string &s, int &k, int start, vector<int>& t) {
        if (start >= s.size()) return 1;
        if (t[start] != -1) return t[start];
        if (s[start] == '0') return 0;

        long long num = 0;
        long long ans = 0;

        for (int end = start; end < s.size(); end++) {
            num = (num * 10) + (s[end] - '0');
            if (num > k) break;
            ans = (ans + f(s, k, end + 1, t) % MOD) % MOD;
        }

        return t[start] = ans;
    }

    int numberOfArrays(string s, int k) {
        vector<int> t(s.size() + 1, -1);
        return f(s, k, 0, t);
    }
};
