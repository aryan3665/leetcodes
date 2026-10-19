class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller=0;
        int equal=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target)smaller++;
            else if(nums[i]==target)equal++;
        }

        while(equal!=0){
            ans.push_back(smaller++);
            equal--;
        }
        return ans;
    }
};