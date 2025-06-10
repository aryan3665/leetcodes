class Solution {
public:
    bool checkfreq(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
            if (mp[c] >= 2) return true;  // check for duplicates
        }
        return false;
    }

    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal) {
            // Check if there's any character that occurs more than once
            return checkfreq(s);
        }

        vector<int> indices;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                indices.push_back(i);
            }
        }

        if (indices.size() != 2) return false;

        // Try swapping the two differing characters
        swap(s[indices[0]], s[indices[1]]);
        return s == goal;
    }
};
