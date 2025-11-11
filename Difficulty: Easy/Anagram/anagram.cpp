class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        map<char,int>mp;
        for(auto&it:s1){
            mp[it]-=1;
        }
         for(auto&it:s2){
            mp[it]+=1;
        }
        for(int i=0;i<mp.size();i++){
            if(mp[i]!=0)return false;
        }
        return true;
    }
};