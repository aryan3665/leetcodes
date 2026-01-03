class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                ans += ch;
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            else {
                while (!st.empty() &&
                      (priority(st.top()) > priority(ch) ||
                      (priority(st.top()) == priority(ch) && ch == '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

    string infixToPrefix(string s) {
        reverse(s.begin(), s.end());

        for (char &ch : s) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        string postfix = infixToPostfix(s);

        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};
