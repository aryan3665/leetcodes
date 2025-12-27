class Solution {
  public:
    int ans(vector<int>& arr, int k, int l, int r) {
        if (l > r) return -1;

        int mid = l + (r - l) / 2;

        if (arr[mid] == k) {
            int left = ans(arr, k, l, mid - 1);
            return (left != -1) ? left : mid;
        }
        else if (arr[mid] > k) {
            return ans(arr, k, l, mid - 1);
        }
        else {
            return ans(arr, k, mid + 1, r);
        }
    }

    int binarysearch(vector<int> &arr, int k) {
        return ans(arr, k, 0, arr.size() - 1);
    }
};
