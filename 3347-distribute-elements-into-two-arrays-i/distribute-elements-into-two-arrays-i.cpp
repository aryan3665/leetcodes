class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> a1;
        vector<int> a2;

        a1.push_back(nums[0]);
        a2.push_back(nums[1]);

        int i = 2;
        int n = nums.size();

        while(i < n) {

            int a = a1.back();
            int b = a2.back();

            if(a > b) {
                a1.push_back(nums[i]);
            }
            else {
                a2.push_back(nums[i]);
            }

            i++;
        }

        vector<int> ans;

        for(auto &it : a1) {
            ans.push_back(it);
        }

        for(auto &it : a2) {
            ans.push_back(it);
        }

        return ans;
    }
};