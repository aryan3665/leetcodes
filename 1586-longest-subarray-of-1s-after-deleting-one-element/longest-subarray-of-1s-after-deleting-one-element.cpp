class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        //ek window size me 1 se jada zero nhi ana chahiye
        int zero=0;
        int maxi=INT_MIN;
        for(int j=0;j<n;j++){
            if(nums[j]==0)zero++;

            while(zero>1){
                if(nums[i]==0)zero--;
                i++;
            }

            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};