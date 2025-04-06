class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         for (int i = 1; i < nums.size(); i++) {
        int key = nums[i]; // current element
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key; // insert key at correct position
    }
       
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};