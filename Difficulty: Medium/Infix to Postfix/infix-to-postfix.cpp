class Solution {
public:
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*'||ch=='/') return 2;
        else if(ch=='+'||ch=='-') return 1;
        else return -1;
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string ans="";

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(isalnum(ch)){
                ans += ch;
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
                while(!st.empty() &&
                      (priority(st.top()) > priority(ch) ||
                      (priority(st.top()) == priority(ch) && ch != '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
