class Solution {
public:
    bool isable(vector<int>& piles, int m, int h) {
        long long k = 0;  // total hours (use long long to avoid overflow)
        for (int i = 0; i < piles.size(); i++) {
            // hours needed for pile[i] = ceil(piles[i] / m)
            k += (piles[i] + m - 1) / m;
            if (k > h) return false; 
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;  

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isable(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
