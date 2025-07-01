// User function template for C++
class Solution {
  public:
  bool allzero(vector<int>&freq){
      for(int&it:freq){
          if(it!=0)return false;
      }
      return true;
  }
    int search(string &pat, string &txt) {
        // code here
        int i=0;
        int j=0;
        int k=pat.size();
        int n=txt.size();
  
        int count=0;
        vector<int>freq(26,0);
        for(int i=0;i<k;i++){
            freq[pat[i]-'a']++;
        }
        
        while(j<n){
           
                 freq[txt[j]-'a']--;
            
           
            
            if(j-i+1==k){
              if(allzero(freq))count++;
                freq[txt[i]-'a']++;
                i++;
                
            }
            j++;
            
        }
        
        return count;
    }
};