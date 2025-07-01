class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int c = 0;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                c++;
            }
        }

        return c + 1;
    }
};

/*
Approach and Intuition:

- Alice might have accidentally held a key too long, causing one group of characters to repeat more than intended.
- The key point is: at most one group of repeated characters might be longer than it should be.
- For every place in the string where the same character repeats (i.e., word[i] == word[i-1]), 
  it's a potential candidate for such an error.
- So we count the number of adjacent repeated characters (`c`).
- For each such repeat, we can consider the possibility that Alice held the key down by mistake and typed it more times.
- However, since Alice can make **at most one** such mistake, we only consider **one such reduction** at a time.
- Therefore, the total number of possible original strings is:
    -> the original string (no error)
    -> plus one for each position where a repeated character could be shortened (only one such shortening allowed)
- Final answer = c + 1
*/
