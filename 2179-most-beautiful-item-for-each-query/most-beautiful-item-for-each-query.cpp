class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(items.begin(), items.end());

        // prefix max beauty
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> ans;

        for (int q : queries) {
            int start = 0, end = items.size() - 1;
            int best = 0;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (items[mid][0] <= q) {
                    best = items[mid][1];
                    start = mid + 1;   // ✅ VERY IMPORTANT
                } else {
                    end = mid - 1;
                }
            }
            ans.push_back(best);
        }
        return ans;
    }
};
