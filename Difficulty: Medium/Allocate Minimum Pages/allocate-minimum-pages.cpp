class Solution {
  public:
  
  bool possible(vector<int>&arr,int maxallowed,int k){
       int s = 1; // Number of students
    int pages = 0; // Pages allocated to the current student

    for (int i = 0; i < arr .size(); i++) {
        pages+=arr[i];
        if(pages>maxallowed){
            s++;
            pages=arr[i];
        }
    }
    return s <= k; 
      
  }
    int findPages(vector<int> &arr, int k) {
        // code here
          int n=arr.size();
          if (k > n) {
        return -1; // More students than books
    }

        int res=-1;
      
          int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Calculate total pages
    }
        int l=*max_element(arr.begin(), arr.end());
        int r=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(arr,mid,k)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return res;
    }
};