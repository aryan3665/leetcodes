class Solution {
public:
    // Function to check if a character is a vowel
    bool isvowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> mp;
        vector<int> nextc(n);
        int last = n;

        // Precompute next vowel positions
        for (int i = n - 1; i >= 0; i--) {
            nextc[i] = last;
            if (!isvowel(word[i])) {
                last = i;
            }
        }

        int i = 0, cons = 0, j = 0;
        long long c = 0;

        while (j < n) {
            char ch = word[j];
            if (isvowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            // Shrinking the window if consonants exceed k
            while (i<n&&cons > k) {
                char ch = word[i];
                if (isvowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            // Checking condition: all vowels must be present, and consonants must be exactly k
            while (i<n&& mp.size() == 5 && cons == k) {
                int idx = nextc[j];
                c += idx - j;  // Update count with the valid substring count
                char ch = word[i];

                if (isvowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }
        return c;
    }
};
