//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void bst(int arr[], int &index, int lower, int upper, int N) {
        if (index == N || arr[index] < lower || arr[index] > upper)
            return;

        int value = arr[index++];
        bst(arr, index, lower, value, N);  // Left subtree
        bst(arr, index, value, upper, N);  // Right subtree
    }

    int canRepresentBST(int arr[], int N) {
        int index = 0;
        bst(arr, index, INT_MIN, INT_MAX, N);
        return index == N;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends