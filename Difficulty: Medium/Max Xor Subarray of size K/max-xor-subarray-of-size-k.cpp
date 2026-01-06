class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        
        int currXor = 0;
        int n=arr.size();

    // XOR of first window
    for(int i = 0; i < k; i++) {
        currXor ^= arr[i];
    }

    int ans = currXor;

    // Slide the window
    for(int i = k; i < n; i++) {
        currXor ^= arr[i];     // add new element
        currXor ^= arr[i-k];   // remove old element

        ans = max(ans, currXor);
    }

    return ans;
    }
};