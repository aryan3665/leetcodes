class Solution {
public:

    // Converts an integer n into its string representation without using to_string
    string func(int64_t n ) {
        string ans = "" ; 
        int64_t d  = log10(n) + 1 ; // number of digits in n
        int64_t p = pow(10 , d) ;   // power of 10 just greater than n
        for(int i  = 0 ; i < d ; i++) {
            int64_t a = n / (p / 10) ; // extract the leftmost digit
            ans += (a + '0') ;         // append digit as a character to ans
            n = n % (p / 10) ;         // remove the leftmost digit from n
            p = p / 10 ;               // decrease divisor for next digit
        }
        return ans ; 
    }

    // Custom binary search to check if string s exists in sorted array a
    bool bs(vector<string>& a ,string s) {
        int l = 0 ; 
        int r = a.size() - 1  ; 

        while(l <= r) {
            // mid calculation (right-biased)
            int m = r - (r - l) / 2 ; 
            if(a[m] == s) { // exact match found
                return true ; 
            }
            cout << a[m] << " " << s << endl; // debug output

            // Find first differing character between a[m] and s
            int ind = 0 ; 
            while(a[m][ind] == s[ind]) {
                ind++ ; 
            }

            // Compare at the first differing position
            if(a[m][ind] > s[ind]) {
                r = m - 1 ; // search left half
            }
            else {
                l = m + 1 ; // search right half
            }
        }
        return false ; // not found
    }

    bool reorderedPowerOf2(int n) {
        // Direct check: if n is already a power of two
        if((n & (n - 1)) == 0) {
            return true  ;
        }
        
        // Map: number of digits -> sorted digit strings of all powers of 2 with that many digits
        unordered_map<int64_t , vector<string>> pre  ; 

        // Precompute all powers of 2 up to 2^31
        for(int64_t i = 0 ; i < 32 ; i++) {
            int d = log10((int64_t)(1 << i)) + 1 ; // number of digits in 2^i
            if(d == 10) { // skip if > 9 digits (constraint)
                break ; 
            } 
            string a = func(1 << i) ;  // convert power of 2 to string
            sort(a.begin() , a.end()) ; // sort digits for permutation comparison

            // Store in map by digit length
            if(pre[d].size() == 0) { 
                vector<string> temp = {a} ; 
                pre[d] = temp ; 
            }
            else {
                pre[d].push_back(a) ; 
            }
        }

        // Process input number
        int d = log10(n) + 1 ; // number of digits in n
        if(d == 10) { // skip if > 9 digits
            return false ; 
        }
        string f = func(n) ; 
        sort(f.begin() , f.end()) ; // sort digits for comparison

        // Sort stored list of powers of 2 with same number of digits
        sort(pre[d].begin() , pre[d].end()) ; 

        // Check if sorted digits of n match any stored sorted digits
        return bs(pre[d] , f) ; 

        return true ; // (Unreachable due to previous return)
    }
};
