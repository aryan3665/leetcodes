class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int sum=0;
        int count=0;
        int i=0;
        int j=0;
        int n=arr.size();
        map<int,int>mp;
        mp[0]=1;
        while(j<n){
            sum+=arr[j];
            if(mp.count(sum)){
                count+=mp[sum];
            }
            mp[sum]++;
           
            j++;
        }
        
        return count;
        
    }
};