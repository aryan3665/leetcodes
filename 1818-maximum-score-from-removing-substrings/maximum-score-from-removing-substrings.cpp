class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> st;

        if (x > y) {
            // First remove "ab", then "ba"
            for (char ch : s) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(ch);
                }
            }

            // Build remaining string from stack
            string remaining = "";
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());

            // Remove "ba"
            for (char ch : remaining) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(ch);
                }
            }

        } else {
            // First remove "ba", then "ab"
            for (char ch : s) {
                if (!st.empty() && st.top() == 'b' && ch == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(ch);
                }
            }

            // Build remaining string from stack
            string remaining = "";
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());

            // Remove "ab"
            for (char ch : remaining) {
                if (!st.empty() && st.top() == 'a' && ch == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(ch);
                }
            }
        }

        return ans;
    }
};
