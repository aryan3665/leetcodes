class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Correct logic: shift n right by k, then AND with 1
        if ((n >> k) & 1)
            return true;
        else
            return false;
    }
};
