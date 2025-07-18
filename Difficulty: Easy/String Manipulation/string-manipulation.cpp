//User function Template for C++

class Solution{
    public:
    int removeConsecutiveSame(vector <string > v) 
    {
        // Your code goes here
        stack<string>st;
      
        int n=v.size();
        for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(v[i]);
        }
        else if(st.top()!=v[i]){
            st.push(v[i]);
          
        }
        else {
        st.pop();
        }
        }
        return st.size();
    } 
};
