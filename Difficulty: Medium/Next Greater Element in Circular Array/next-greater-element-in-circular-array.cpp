class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        // Loop through the array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int current = arr[i % n];

            while (!st.empty() && arr[st.top()] < current) {
                ans[st.top()] = current;
                st.pop();
            }

            if (i < n) {
               
                st.push(i);
            }
        }

        return ans;
    }
};
