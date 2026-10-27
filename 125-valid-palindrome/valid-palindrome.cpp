

class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";

        for (int l = 0; l < s.size(); l++) {
            if (isalnum((unsigned char)s[l])) {
                k += tolower((unsigned char)s[l]);
            }
        }

        int i = 0;
        int j = k.size() - 1;

        while (i < j) {
            if (k[i] != k[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
