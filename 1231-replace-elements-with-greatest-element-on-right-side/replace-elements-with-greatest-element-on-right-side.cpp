class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //vahiyat tarreka
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            //i ke left side me max element serch karo aur usee replace kardo,
            int maxi=INT_MIN;
            for(int j=i+1;j<n;j++){
                maxi=max(arr[j],maxi);
            }
            arr[i]=maxi;
        }
        arr[n-1]=-1;
        return arr;
    }
};