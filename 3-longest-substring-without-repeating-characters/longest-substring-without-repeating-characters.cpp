class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        unordered_map<char,int> mp;
        int maxi = 0;

        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;

            // shrink window until all characters are unique
            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }

            // update answer (window size = j - i + 1)
            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};
