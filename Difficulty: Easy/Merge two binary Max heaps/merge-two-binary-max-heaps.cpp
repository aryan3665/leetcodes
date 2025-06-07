// User function Template for C++

class Solution {
  public:
  void heapify(vector<int>&v,int index,int n){
      int largest=index;
      int left=2*index+1;
      int right=2*index+2;
      if(left<n&&v[left]>v[largest]){
          largest=left;
      }
       if(right<n&&v[right]>v[largest]){
          largest=right;
      }
      if(largest!=index){
          swap(v[largest],v[index]);
          heapify(v,largest,n);
      }
  }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(a[i]);
        }
         for(int i=0;i<m;i++)
        {
            v.push_back(b[i]);
        }
        n=v.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(v,i,n);
            
        }
        return v;
    }
};