//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    void per(string &s, vector<string> &ans, int index) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            swap(s[i], s[index]); // Swap the current index with the loop index
            per(s, ans, index + 1); // Recur for the next index
            swap(s[i], s[index]); // Backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> ans;
        per(s, ans, 0);
        sort(ans.begin(), ans.end()); // Optional: Sort to have permutations in lexicographical order
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); // Optional: Remove duplicates
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends