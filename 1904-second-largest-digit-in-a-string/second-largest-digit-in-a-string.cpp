class Solution {
public:
    int secondHighest(string s) {
        set<int> digits; // Set ensures uniqueness
        for (char c : s) {
            if (isdigit(c)) {
                digits.insert(c - '0');
            }
        }

        if (digits.size() < 2) return -1;

        auto it = digits.rbegin(); // reverse iterator for largest
        ++it; // move to second largest
        return *it;
    }
};
