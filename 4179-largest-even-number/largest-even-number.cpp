class Solution {
public:
    string largestEven(string s) {
        //traverse karlo last of string se jaha pe 1st 2 mile waha tak ki string from start is the answer
        int index=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='2'){
                index=i;
                break;
            }
        }
    if(index==-1)return "";
        string ans=s.substr(0,index+1);
        return ans;
    }
};