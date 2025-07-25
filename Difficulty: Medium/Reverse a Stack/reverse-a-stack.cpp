// User function Template for C++

class Solution {
  public:
    void Reverse(stack<int> &st) {
        if(st.empty())return ;
        
        int top=st.top();
        st.pop();
        
        Reverse(st);
        
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
            
        }
        st.push(top);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};