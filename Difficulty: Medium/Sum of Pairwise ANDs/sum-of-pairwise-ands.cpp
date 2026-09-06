class Solution {
public:
    long long pairAndSum(vector<int>& arr) {
        long long sum = 0;

        for (int bit = 0; bit < 32; bit++) {
            long long cnt = 0;

            for (int x : arr) {
                if (x & (1LL << bit))
                    cnt++;
            }

            sum += (cnt * (cnt - 1) / 2) * (1LL << bit);
        }

        return sum;
    }
};