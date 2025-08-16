class Solution {
public:
    int maximum69Number (int num) {
        // Convert number to string
        string s = to_string(num);
        
        // Traverse from left to right
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9'; // flip the first '6' we find
                break;      // only change once
            }
        }
        
        // Convert back to integer
        return stoi(s);
    }
};
