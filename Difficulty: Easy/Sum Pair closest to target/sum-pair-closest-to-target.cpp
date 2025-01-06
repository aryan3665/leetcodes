//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int l = 0;
        int r = n-1;
        
        vector<int>result;
        int sum_diff = INT_MAX;
        int max_absolute_diff = INT_MIN;
        
        while(l < r){
            
            int sum = arr[l]+arr[r];
            int diff = abs(target-sum);
            int absolute_diff= arr[r]-arr[l];
            
            if(diff < sum_diff || (diff == sum_diff && absolute_diff > max_absolute_diff)){
                sum_diff = diff;
                max_absolute_diff = absolute_diff;
                result = {arr[l],arr[r]};
            }
            if(sum > target){
                r--;
            }
            else if(sum < target){
                l++;
            }
            else{
                return {arr[l],arr[r]};
            }
        }
        return result;
    }
};
        
    


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends