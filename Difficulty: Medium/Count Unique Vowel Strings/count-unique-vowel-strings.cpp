#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long vowelCount(string& s) {
        // Index mapping: 0‑a, 1‑e, 2‑i, 3‑o, 4‑u
        long long freq[5] = {0};
        
        // 1. Count each vowel's occurrences
        for (char ch : s) {
            switch (ch) {
                case 'a': freq[0]++; break;
                case 'e': freq[1]++; break;
                case 'i': freq[2]++; break;
                case 'o': freq[3]++; break;
                case 'u': freq[4]++; break;
                default : break;  // ignore consonants
            }
        }
        
        // 2. Find number of distinct vowels & product of choices
        long long product = 1;          // product of ways to pick each vowel
        int distinct = 0;               // how many different vowels appear
        for (int i = 0; i < 5; ++i) {
            if (freq[i] > 0) {
                product *= freq[i];
                ++distinct;
            }
        }
        if (distinct == 0) return 0;    // no vowels → no strings
        
        // 3. Compute factorial of 'distinct' (d! where d ≤ 5)
        long long fact = 1;
        for (int i = 2; i <= distinct; ++i) fact *= i;
        
        // 4. Final answer
        return product * fact;
    }
};