//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxArea(vector<int> &arr) {
        // code here
        int start=0;
        int end=arr.size()-1;
        int maxi=0;
        
        while(start<=end){
            int b=end-start;
            maxi=max(maxi,(b*min(arr[start],arr[end])));
            if(arr[start]<arr[end]){
                start++;
            }
            else {
                end--;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxArea(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends