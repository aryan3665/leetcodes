class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1=INT_MAX;
        int n2=INT_MAX;
        int n3;
        for(int i=0;i<nums.size();i++){
            n3=nums[i];
            if(n3<=n1){
                n1=n3;
            }
            else if(n3<=n2){
                n2=n3;
            }
            else{
                return true;
            }
        }
        return false;
    }
};