class Solution {
public:
    // helper to compute mid^n safely (and stop if it exceeds m)
    long long power(long long mid, int n, int m) {
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= mid;
            if (ans > m) return ans;  // prevent overflow
        }
        return ans;
    }

    int nthRoot(int n, int m) {
        int l = 1, r = m/n;  // search range

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long val = power(mid, n, m);

            if (val == m) return mid;      // found exact root
            else if (val < m) l = mid + 1;
            else r = mid - 1;
        }
        return -1; // no integer root
    }
};
