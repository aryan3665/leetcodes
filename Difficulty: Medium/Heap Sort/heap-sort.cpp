//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
  void heapify(vector<int>&arr,int index,int n){
      int largest=index;
      int left=2*index+1;
      int right=2*index+2;
      
      if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, largest, n);
    }
      
  }
  void build(vector<int>&arr,int n){
        for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
  }
  
  void sort(vector<int>&arr,int n){
       for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
  }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        build(arr,arr.size());
        sort(arr,arr.size());
       
        
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
        Solution obj;
        obj.heapSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends