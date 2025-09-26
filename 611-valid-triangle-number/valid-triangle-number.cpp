class Solution {
public:

    int fun(vector<int>& nums,int i,int j){
        int target = nums[i]+nums[j];
        int low = j+1,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<target){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans==-1){
            return 0;
        }
        return ans-j;
    }

    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                cnt+=fun(nums,i,j);
            }
        }
        return cnt;
    }
};