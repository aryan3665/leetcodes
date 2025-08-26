class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        // code here
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(mp[arr[i]]==2)ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
