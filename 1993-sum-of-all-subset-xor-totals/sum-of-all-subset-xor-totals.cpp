class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
         int n = arr.size();
    int totalSum = 0;

    // Loop through all subsets (2^n subsets)
    for (int i = 0; i < (1 << n); ++i) {
        int xor_sum = 0;

        // For each subset, pick elements where bit is set
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                xor_sum ^= arr[j];
            }
        }

        totalSum += xor_sum;
    }

    return totalSum;
    }
};