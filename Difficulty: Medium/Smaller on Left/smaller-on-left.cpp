class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int>st;
        vector<int>ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};