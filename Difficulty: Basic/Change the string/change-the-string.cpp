//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:

    string modify(string& s) {
        // your code here
        int n=s.size();
        if(s[0]>='a'&& s[0]<='z'){
            for(int i=0;i<n;i++){
                if(s[i]>='A'&&s[i]<='Z')
                s[i]=char(s[i]+32);
            }
        }
        else{
           for(int i=0;i<n;i++){
                if(s[i]>='a'&&s[i]<='z')
                s[i]=char(s[i]-32);
            } 
        }
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.modify(s) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends