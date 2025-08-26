class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        //we will use 2 pointer approch
        
        int i=0;
        int j=0;
        string temp="";
        while(i<s1.size()&&j<s2.size()){
            if(s1[i]==s2[j]){
                temp+=s1[i];
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(temp==s1)return true;
        return false;
    }
};