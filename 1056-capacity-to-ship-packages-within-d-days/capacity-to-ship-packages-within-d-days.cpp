class Solution {
public:
    bool isok(int val, vector<int>& weights, int days) {
        int d = 1; 
        int s = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > val) return false;

            if (s + weights[i] > val) { 
                d++;
                s = weights[i];
            } else {
                s += weights[i];
            }
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l =1;
        int r = accumulate(weights.begin(), weights.end(), 0); // max capacity
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isok(mid, weights, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
