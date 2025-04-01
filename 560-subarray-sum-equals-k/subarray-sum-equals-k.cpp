class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int>mp;
    mp[0]=1;
      int currentsum = 0;
    int count = 0;
    for(int num:nums){
        currentsum+=num;

        if(mp.find(currentsum-k)!=mp.end()){
            count+=mp[currentsum-k];
        }
        mp[currentsum]++;

    }
    return count;
}

};