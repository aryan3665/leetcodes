class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        stack<int>st;
        for(auto&v:arr){
            st.push(v);
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=st.top();
            st.pop();
        }
    }
};