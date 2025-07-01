class Solution {
public:
    // Helper function to count subarrays with at most k distinct integers
    int sw(vector<int>& arr, int k) {
        int i = 0, j = 0;
        int n = arr.size();
        int count = 0;
        map<int, int> mp;

        while (j < n) {
            mp[arr[j]]++;

            while (mp.size() > k) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

    int exactlyK(vector<int>& arr, int k) {
        return sw(arr, k) - sw(arr, k - 1);
    }
};
