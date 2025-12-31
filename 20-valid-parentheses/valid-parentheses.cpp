class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')st.push(s[i]);
            else{
                if(st.empty())return false;
                else{
                    char c=st.top();
                    st.pop();
                    if(c=='('&& s[i]==')'||(c=='['&&s[i]==']')||(c=='{'&&s[i]=='}'))continue;
                    else return false;
                }
            }

        }

        return st.empty();
    }
};