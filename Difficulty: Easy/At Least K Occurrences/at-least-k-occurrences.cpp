class Solution {
  public:
    int firstElementKTime(vector<int>& A, int k) {
        // write code
         map<int,int>mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
        if (mp[A[i]]>=k)return A[i];
    }
  
    
    return -1;
    
    }
};