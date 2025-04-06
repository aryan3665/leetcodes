class Solution {
public:
void merge(vector<int>eve,vector<int>odd,vector<int>&ans){
    int i=0;
    int j=0;
    while(i<eve.size()&&j<odd.size()){
        ans.push_back(eve[i++]);
        ans.push_back(odd[j++]);
    }
    while(i<eve.size()){
        ans.push_back(eve[i++]);
    }

     while(j<odd.size()){
        ans.push_back(odd[j++]);
    }
}
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>eve,odd,ans;
        if(n<=2)return nums;
        else{
           for(int i=0;i<n;i++){
            if(i%2==0){
                eve.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
           }
           sort(eve.begin(),eve.end());
           sort(odd.rbegin(),odd.rend());
           merge(eve,odd,ans);
        }
        return ans;;
    }
};