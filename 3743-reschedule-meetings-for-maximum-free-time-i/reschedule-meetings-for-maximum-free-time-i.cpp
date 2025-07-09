class Solution {
public:
    int maxFreeTime(int et, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
        vector<int> g;
        ++k;  // we need k gaps, including start and end
        g.push_back(s[0]);  // free time before first task

        // free time between tasks
        for (int i = 0; i < n - 1; i++) {
            g.push_back(s[i + 1] - e[i]);
        }

        // free time after last task
        g.push_back(et - e[n - 1]);

        int ans = 0;

        // initial sum of first k gaps
        for (int i = 0; i < k; i++) {
            ans += g[i];
        }

        int t = ans;

        // sliding window to find max sum of k consecutive gaps
        for (int i = k; i < g.size(); i++) {
            t -= g[i - k];
            t += g[i];
            ans = max(ans, t);
        }

        return ans;
    }
};