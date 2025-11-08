class Solution {
public:
    bool iscorrect(int val, vector<int>& arr, int k) {
        int s = 0;
        for (int i = 0; i < arr.size(); i++) {
            s += ceil((double)arr[i] / val);  // ensure floating-point division
        }
        return (s <= k);
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1;
        int maxi = *max_element(arr.begin(), arr.end());
        int r = maxi;
        int ans = -1;  // initialize ans safely

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (iscorrect(mid, arr, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
