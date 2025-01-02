#include <vector>
#include <string>

class Solution {
public:
    bool isvowel(char ch) {
        // Check if the character is a vowel
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        int q = queries.size();
        std::vector<int> ans(q);
        int n = words.size();
        std::vector<int> cumsum(n);
        int sum = 0;

        // Calculate cumulative sums of words that start and end with vowels
        for (int i = 0; i < n; i++) {
            if (isvowel(words[i].back()) && isvowel(words[i][0])) {
                sum++;
            }
            cumsum[i] = sum;
        }

        // Answer the queries
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = cumsum[r] - (l > 0 ? cumsum[l - 1] : 0);
        }

        return ans; // Return the result vector
    }
};