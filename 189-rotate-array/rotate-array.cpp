class Solution {
public:
void reverse(vector<int>&arr,int start,int ind){
    while(start<=ind){
        swap(arr[start],arr[ind]);
        ind--;
        start++;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
     reverse(nums,0,n-k-1);
     reverse(nums,n-k,n-1);
     reverse(nums,0,n-1);
       
    }
};