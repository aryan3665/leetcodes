class Solution {
  public:
    void print_divisors(int n) {
        vector<int> big;  // to store the larger divisors
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";   // smaller divisor
                if (i != n / i) {
                    big.push_back(n / i); // store larger divisor
                }
            }
        }
        // print the larger divisors in correct order
        for (int i = big.size() - 1; i >= 0; i--) {
            cout << big[i] << " ";
        }
    }
};
