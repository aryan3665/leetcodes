class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;

    }
};