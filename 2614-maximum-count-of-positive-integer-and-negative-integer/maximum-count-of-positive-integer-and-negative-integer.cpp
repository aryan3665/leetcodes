class Solution {
public:
    int maximumCount(vector<int>& nums) {


     int posIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
      int posCount = nums.size() - posIndex;
      int firstzero=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
      int neg=firstzero;
      return max(posCount,neg);
    
    }
};