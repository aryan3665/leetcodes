class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // 2 se chhote prime nahi hote
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {  // Note: i * i < n
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true); // Count primes
    }
};
