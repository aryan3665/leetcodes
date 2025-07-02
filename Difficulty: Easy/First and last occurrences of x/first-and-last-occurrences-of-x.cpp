class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Code here
        int n=arr.size();
        int start=0;
        int end=n-1;
        int first=-1;
        int second=-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        start=0;
        end=n-1;
            while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                second=mid;
                start=mid+1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        vector<int>ans;
        if(first==-1){
          ans.push_back(first);  
        }
        else{
            ans.push_back(first);
        
        ans.push_back(second);
        }

        return ans;
        
    }
};