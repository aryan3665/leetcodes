class Solution {
public:
bool isanswer(vector<int>nums,int mid){
    vector<long long >arr(begin(nums),end(nums));
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        if(arr[i]>mid)return false;
        else{
long long  buffer=mid-arr[i];
arr[i+1]-=buffer;
        }
        
    }
    return arr[n-1]<=mid;

}
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int ans;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isanswer(nums, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};