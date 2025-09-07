class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for (auto &it : nums) {
            mp[it]++;
        }

        for (auto &p : mp) {
            if (p.second > n / 2) {  // majority means strictly greater than n/2
                return p.first;      // return the element itself
            }
        }
        return -1;  // should not happen as per problem guarantee
    }
};
