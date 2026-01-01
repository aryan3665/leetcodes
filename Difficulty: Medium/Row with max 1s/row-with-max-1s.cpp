class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size();
        int n = arr[0].size();

        int maxi = 0;
        int index = -1;

        for (int i = 0; i < m; i++) {
            int countone = n - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());

            if (countone > maxi) {
                maxi = countone;
                index = i;
            }
        }
        return index;
    }
};
