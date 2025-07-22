class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        unordered_set<int> s;

        // Insert only positive numbers into the set
        for (int num : arr) {
            if (num > 0) {
                s.insert(num);
            }
        }

        // Check from 1 upwards for the first missing number
        int i = 1;
        while (true) {
            if (s.find(i) == s.end()) {
                return i;
            }
            i++;
        }
    }
};
