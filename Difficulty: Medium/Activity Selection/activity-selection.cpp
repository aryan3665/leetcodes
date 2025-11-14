class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {

        int n = start.size();
        if (n == 0) return 0; // edge case

        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back({start[i], finish[i]});
        }

        sort(res.begin(), res.end(), [](pair<int,int> &a, pair<int,int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int cnt = 1;
        int endTime = res[0].second;

        for (int i = 1; i < n; i++) {
            if (res[i].first >endTime) {
                cnt++;
                endTime = res[i].second;
            }
        }

        return cnt;
    }
};
