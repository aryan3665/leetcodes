class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int i=0;
        int j=0;
        int n=s.size();
        vector<int>freq(26,0);
        //sliding window
        int result=0;
        int distinct=0;
        
        while(j<n){
            
           
            if(freq[s[j]-'a']==0){
                distinct+=1;
                
            }
            freq[s[j]-'a']++;
            if(j-i+1>k){
                freq[s[i]-'a']--;
                
                if(freq[s[i]-'a']==0 ){
                    distinct--;
                }
                  i++;
            }
            
            if(j-i+1==k){
                if(distinct==k-1){
                    result+=1;
                }
            }
         
            j++;
        }
        
        return result;
    }
};