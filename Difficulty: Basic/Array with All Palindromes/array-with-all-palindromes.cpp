class Solution {
public:
    bool isPalindrome(int n) {
        int temp = n;
        int rev = 0;

        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        return rev == temp;
    }

    bool isPalinArray(vector<int> &arr) {
        for (int x : arr) {
            if (!isPalindrome(x))
                return false;
        }
        return true;
    }
};