//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  long long fact(long long n){

    if(n==1)return 1*1LL;

    return n*fact(n-1);

}

    long long getSum(vector<int>& arr) {
        // write code here
        int n=arr.size();
         int f=fact(n);

         int m=f/n;     
          long long sum=0;

    for(int i=0;i<n;i++)sum+=arr[i];

    long long mult = sum*m;
            long long ans=0, k=1;

    for(int i=0;i<n;i++){

        ans=((ans%1000000007)+(mult%1000000007)*(k%1000000007))%1000000007;

        k=k*10;
    }
    return ans;
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
        cout << obj.getSum(arr) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends