class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
       int n=nums.size();
       //left max nikalna hai 1st step
       vector<int>leftmax(n);
       leftmax[0]=nums[0];
       for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],nums[i]);
       }
       //2nd step right smaller nikalenge
       vector<int>rightsmall(n);
       rightsmall[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
        rightsmall[i]=min(rightsmall[i+1],nums[i]);
       }

       //abb ek answer vector me answer calc karenge
       vector<int>ans(n);
       ans[n-1]=leftmax[n-1];
       for(int i=n-2;i>=0;i--){
        if(rightsmall[i+1]<leftmax[i]){
            ans[i]=ans[i+1];
        }
        else{
            ans[i]=leftmax[i];
        }

       }
       return ans;
    }
};