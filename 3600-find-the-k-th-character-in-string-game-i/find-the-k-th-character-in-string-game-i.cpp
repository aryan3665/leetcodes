class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        string curr = "";
        while (word.size() <= k) {
            for (int i = 0; i < word.size(); i++) {
                if (word[i] != 'z') {
                    curr += char(word[i] + 1);
                } else if (word[i] == 'z') {
                    curr += 'a';
                }
            }
            word += curr;
            curr = "";
        }
        int j = 0;
        while (j != k - 1) {
            j++;
        }
        return word[j];
    }
};