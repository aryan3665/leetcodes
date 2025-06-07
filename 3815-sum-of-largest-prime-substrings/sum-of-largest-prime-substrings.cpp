class Solution {
public:
   bool isprime(long long k) {
    if (k < 2) return false;
    for (long long i = 2; i * i <= k; i++) {
        if (k % i == 0)
            return false;
    }
    return true;
}
    long long sumOfLargestPrimes(string s) {
            int n = s.size();
    set<long long> st;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n ; j++) { // substr of at most 12 digits (to stay in long long)
            string sub = s.substr(i, j - i + 1);

            // Skip leading zeros (except "0")
            if (sub.size() > 1 && sub[0] == '0') continue;

            long long k = stoll(sub);
            if (isprime(k)) {
                st.insert(k);
            }
        }
    }

    // Sum all primes found
    long long sum = 0;
    int pic=0;
    for (auto prime=st.rbegin();prime!=st.rend()&&pic<3;++prime) {
        sum += *prime;
        ++pic;
    }
    return sum;
}
    
};