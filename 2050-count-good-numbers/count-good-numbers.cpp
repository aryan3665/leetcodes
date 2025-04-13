class Solution {
public:
    const int mod = 1e9 + 7;
    long long power(long long base, long long exp, long long mod) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2, mod);
        long long result = (half * half) % mod;
        if (exp % 2 == 1) {
            result = (base * result) % mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long pow5 = power(5, even, mod);
        long long pow4 = power(4, odd, mod);

        return (int)((pow5 * pow4) % mod);
    }
};