class Solution {
public:

 bool allzero(vector<int>&freq){
      for(int&it:freq){
          if(it!=0)return false;
      }
      return true;
  }
    vector<int> findAnagrams(string s, string p) {
         int i=0;
        int j=0;
        int k=p.size();
        int n=s.size();
         vector<int>ans;
        vector<int>freq(26,0);
        for(int i=0;i<k;i++){
            freq[p[i]-'a']++;
        }
        
        while(j<n){
           
                 freq[s[j]-'a']--;
            
           
            
            if(j-i+1==k){
              if(allzero(freq))ans.push_back(i);
                freq[s[i]-'a']++;
                i++;
                
            }
            j++;
            
        }
        
        return ans;
    }
};