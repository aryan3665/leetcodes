class Solution {
public:
    vector<string> result;
    int n; // Move n inside the class scope

    bool isvalid(string str) {
        if (str.size() > 1 && str[0] == '0') return false; // Prevent "01", "00", etc.
        int val = stoi(str);
        return val <= 255;
    }

    void solve(const string& s, int idx, int parts, string curr) {
        if (idx == n && parts == 4) {  // Valid IP found
            curr.pop_back();  // Remove last dot
            result.push_back(curr);
            return;
        }
        if (idx >= n || parts >= 4) return;  // Invalid path

        // Try 1-digit part
        solve(s, idx + 1, parts + 1, curr + s.substr(idx, 1) + ".");

        // Try 2-digit part
        if (idx + 2 <= n && isvalid(s.substr(idx, 2))) {
            solve(s, idx + 2, parts + 1, curr + s.substr(idx, 2) + ".");
        }

        // Try 3-digit part
        if (idx + 3 <= n && isvalid(s.substr(idx, 3))) {
            solve(s, idx + 3, parts + 1, curr + s.substr(idx, 3) + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size(); 
        if (n > 12 || n < 4) return {}; // Valid IPs must have 4-12 chars
        result.clear();
        solve(s, 0, 0, "");
        return result;
    }
};
