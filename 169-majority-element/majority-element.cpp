class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                element=nums[i];
                cnt=1;
            }
            else  if(nums[i]==element){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element){
                cnt++;
            }
        }
        if(cnt>n/2)return element;
        return -1;
    }
};