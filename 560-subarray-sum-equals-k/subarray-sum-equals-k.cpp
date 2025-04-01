class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
    int count = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) { 
            sum += nums[j];  // Instead of third loop
            if (sum == k) count++;
        }
    }
    
    return count;
}

};