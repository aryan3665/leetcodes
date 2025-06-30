class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<int> v;
        int c1= 0;
        int c2=0;
        int ans;
        int maxi=INT_MIN;
        int n=nums.size();
        for (int i = 0; i < n ; i++) {
            int key = nums[i];
            for (int j = 0; j < n; j++) {
                if (nums[j] == key) {
                    c1++;
                }
                if(nums[j]==key+1){
                    c2++;
                }
             
            }
            if(c2==0){
                ans=0;
            }
            else{
               ans=c1+c2;
                
            }
             c1=0;
             c2=0;
               maxi=max(maxi,ans);
        }

    return maxi;
    }
};