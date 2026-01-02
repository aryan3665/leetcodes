class Solution {
public:
    long long formula(long long m, long long x) {
        return m * x - (m * (m + 1)) / 2;
    }

    bool ispossible(long long mid, int n, int index, int maxSum) {
        long long leftcount = index;
        long long rightcount = n - index - 1;

        long long leftsum =
            formula(min(leftcount, mid - 1), mid)
            + max(0LL, leftcount - (mid - 1));

        long long rightsum =
            formula(min(rightcount, mid - 1), mid)
            + max(0LL, rightcount - (mid - 1));

        long long total = leftsum + mid + rightsum;
        return total <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        long long l = 1;
        long long r = maxSum;
        long long ans = 1;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (ispossible(mid, n, index, maxSum)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (int)ans;
    }
};
