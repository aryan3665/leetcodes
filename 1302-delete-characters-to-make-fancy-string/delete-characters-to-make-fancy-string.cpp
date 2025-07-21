class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 1;  // Start with 1 since the first char always counts

        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;  // Reset count when char changes
            }

            if (count <= 2) {
                ans += s[i];  // Only add if not 3 or more in a row
            }
        }

        return ans;
    }
};
