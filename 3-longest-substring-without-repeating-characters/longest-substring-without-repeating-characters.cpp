class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int>hash(256,-1);  // Initialize all values to -1

        int l = 0, r = 0, maxl = 0;
        int n = s.size();

        while (r < n) {
            if (hash[s[r]] != -1) {  // If character already seen
                l = max(l, hash[s[r]] + 1);  // Move left pointer forward
            }

            int len = r - l + 1;
            maxl = max(maxl, len);
            hash[s[r]] = r;  // Update index of current character
            r++;
        }
        return maxl;
    }
};