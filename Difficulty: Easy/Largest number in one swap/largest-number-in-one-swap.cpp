class Solution {
  public:
    string largestSwap(string &s) {
        // code here
         int n = s.size();

    // Store last occurrence of each character
    vector<int> last(256, -1);
    for (int i = 0; i < n; i++) {
        last[(unsigned char)s[i]] = i;
    }

    // Traverse from left, look for a bigger char later
    for (int i = 0; i < n; i++) {
        for (char ch = 'z'; ch > s[i]; ch--) {
            if (last[ch] > i) {
                // Swap with the rightmost occurrence of this larger char
                swap(s[i], s[last[ch]]);
                return s;
            }
        }
    }

    return s; // already maximum
        
    }
};