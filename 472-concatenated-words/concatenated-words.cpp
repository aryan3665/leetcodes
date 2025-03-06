class Solution {
public:
    bool isconcatenated(string word, unordered_set<string>& st, unordered_map<string, bool>& memo) {
        if (memo.find(word) != memo.end()) return memo[word]; // Memoization

        int l = word.length();
        for (int i = 0; i < l; i++) {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if ((st.find(prefix) != st.end() && isconcatenated(suffix, st, memo)) ||
                (st.find(prefix) != st.end() && st.find(suffix) != st.end())) {
                return memo[word] = true;
            }
        }
        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words), end(words));
        vector<string> result;
        unordered_map<string, bool> memo; // Memoization map

        for (string word : words) {
            st.erase(word); // Remove current word to avoid self-counting
            if (isconcatenated(word, st, memo)) {
                result.push_back(word);
            }
            st.insert(word); // Restore word in set
        }
        return result;
    }
};
