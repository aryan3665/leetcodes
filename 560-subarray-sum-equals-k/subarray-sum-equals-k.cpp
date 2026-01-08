class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int sum=0;
        int count=0;
        int i=0;
        int j=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        while(j<n){
            sum+=arr[j];
            if(mp.count(sum-k)){
                count+=mp[sum-k];
            }
            mp[sum]++;
           
            j++;
        }
        
        return count;
         
    }
};