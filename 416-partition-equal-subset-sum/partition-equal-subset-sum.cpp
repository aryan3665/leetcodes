class Solution {
public:
  bool solve(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum + 1, false);
    
    // Base case: sum 0 is always possible
    prev[0] = true;
    
    // Base case: first element
    if (arr[0] <= sum) {
        prev[arr[0]] = true;
    }
    
    for (int i = 1; i < n; i++) {
        vector<bool> curr(sum + 1, false);
        curr[0] = true; // base case
        
        for (int j = 1; j <= sum; j++) {
            bool notPick = prev[j];
            bool pick = false;
            if (j >= arr[i]) {
                pick = prev[j - arr[i]];
            }
            curr[j] = notPick || pick;
        }
        prev = curr;
    }
    
    return prev[sum];
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        if (sum % 2 != 0)
            return false;
        int n = nums.size();

        return solve(nums, sum / 2);
    }
};