class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        // If the lengths are different, they cannot be close
        if (n1 != n2) {
            return false;
        }

        vector<int> w1(26, 0);
        vector<int> w2(26, 0);
        unordered_set<char> set1, set2;

        // Count frequencies and collect unique characters
        for (char c : word1) {
            w1[c - 'a']++;
            set1.insert(c);
        }
        for (char c : word2) {
            w2[c - 'a']++;
            set2.insert(c);
        }

        // Check if both sets of unique characters are the same
        if (set1 != set2) {
            return false;
        }

        // Sort the frequency vectors and compare
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());

        return w1 == w2;
    }
};