class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0, n = word.size();

        for (char c : word) {
            if (isupper(c)) upperCount++;
        }

        // Valid cases:
        // 1. All uppercase (upperCount == n)
        // 2. All lowercase (upperCount == 0)
        // 3. Only the first letter is uppercase (upperCount == 1 && isupper(word[0]))
        return (upperCount == n || upperCount == 0 || (upperCount == 1 && isupper(word[0])));
    }
};
