class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n=s.size();
       vector<char>upp;
       vector<char>low;
       for(int i=0;i<n;i++){
           if((s[i]>='A'&&s[i]<='Z')){
             upp.push_back(s[i]);  
           }
           else{
               low.push_back(s[i]);
           }
       }
       sort(upp.begin(),upp.end());
       sort(low.begin(),low.end());
       int p=0;
       int l=0;
     for(int i=0;i<n;i++){
         if(s[i]>='A'&&s[i]<='Z'){
             s[i]=upp[p];
             p++;
         }
         else{
             s[i]=low[l];
             l++;
         }
     }
     
     return s;
    }
};