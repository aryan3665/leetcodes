class Solution {
public:

    int countLessEqual(vector<int>& arr, int x) {

        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {

            int low = i + 1;
            int high = n - 1;

            while (low < high) {

                int sum = arr[i] + arr[low] + arr[high];

                if (sum <= x) {
                    count += high - low;
                    low++;
                }
                else {
                    high--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int>& arr, int l, int r) {

        sort(arr.begin(), arr.end());

        return countLessEqual(arr, r)
             - countLessEqual(arr, l - 1);
    }
};