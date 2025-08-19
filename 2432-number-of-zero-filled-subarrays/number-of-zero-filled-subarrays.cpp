class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {  long long n=nums.size();
    long long result=0;
long long i=0;
   
    while(i<n){
         long long  l=0;
        if(nums[i]==0){
            while(i<n&&nums[i]==0){
                i++;
                l++;
            }
            
        }
        else{
            i++;
        }
        result+=l*(l+1)/2;
    }
    return result;
    }
};