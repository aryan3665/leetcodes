class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int N = right + 1;  // Limit for the sieve
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect prime numbers in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest prime pair
        if (primes.size() < 2) return {-1, -1};  // No valid pairs

        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
     
    }
};