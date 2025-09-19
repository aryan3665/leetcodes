class Solution {
  public:
    int minParentheses(string& s) {
        // code here
          stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (!st.empty() && st.top() == '(') {
                st.pop(); // valid pair
            } else {
                st.push(c); // unmatched closing
            }
        }
    }
    return st.size(); // all unmatched parentheses remain
}
        
    
};