class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pre[i]=arr[i]+pre[i-1];
        }
        int sum=pre[n-1];
        for(int i=0;i<n;i++){
            if(sum-pre[i]==pre[i])return true;
        }
        return false;
    }
};
