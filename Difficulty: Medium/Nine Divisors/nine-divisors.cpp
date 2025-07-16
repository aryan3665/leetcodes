class Solution {
  public:
  // Sieve of Eratosthenes
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= limit; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= limit; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}
    int countNumbers(int n) {
        // Code Here
         int count = 0;
    int limit = sqrt(n) + 1;

    vector<int> primes = generatePrimes(limit);

    // Case 1: p^8 ≤ n
    for(int p : primes) {
        long long power = 1;
        for(int i = 0; i < 8; i++) {
            power *= p;
            if(power > n) break;
        }
        if(power <= n) count++;
    }

    // Case 2: p^2 * q^2 ≤ n
    int size = primes.size();
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            long long num = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
            if(num <= n) count++;
            else break; // further j will be larger, so break inner loop
        }
    }

    return count;
        
    }
};