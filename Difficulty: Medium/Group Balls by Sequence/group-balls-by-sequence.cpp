class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : arr) freq[num]++;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            while (freq[num] > 0) {
                for (int i = 0; i < k; i++) {
                    if (freq[num + i] <= 0) return false;
                    freq[num + i]--;
                }
            }
        }
        return true;
    }
};
