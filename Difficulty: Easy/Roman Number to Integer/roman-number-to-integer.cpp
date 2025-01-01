//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        map<char, int> romanNumerals;

    
    romanNumerals['I'] = 1;
    romanNumerals['V'] = 5;
    romanNumerals['X'] = 10;
    romanNumerals['L'] = 50;
    romanNumerals['C'] = 100;
    romanNumerals['D'] = 500;
    romanNumerals['M'] = 1000;
    
    long long n=s.size();
    long long val=0;
    for(long long i=0;i<n;i++){
        if(romanNumerals[s[i]]>romanNumerals[s[i+1]]){
            val+=romanNumerals[s[i]];
        }
        else if(romanNumerals[s[i]]<romanNumerals[s[i+1]]){
            val+=(romanNumerals[s[i+1]]-romanNumerals[s[i]]);
            i++;
        }
         else if(i==n-1|| romanNumerals[s[i]]==romanNumerals[s[i+1]]) {
            val+=romanNumerals[s[i]];
        }
    }
    return val;
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
        cout << ob.romanToDecimal(s) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends