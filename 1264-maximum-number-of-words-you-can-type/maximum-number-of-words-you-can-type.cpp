class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool canType = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {  
                if (canType) count++;   // if word is valid, count it
                canType = true;         // reset for next word
            } 
            else if (st.find(text[i]) != st.end()) {
                canType = false;        // broken letter found → word invalid
            }
        }

        return count;
    }
};
