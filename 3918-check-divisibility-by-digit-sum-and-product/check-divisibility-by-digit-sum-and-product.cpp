class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum=0;

        int digitproduct=1;
        int rem=0;
        int orignal=n;
        while(n!=0){
            rem=n%10;
            digitsum+=rem;
            digitproduct*=rem;
            n=n/10;
        }
        return (orignal%(digitsum+digitproduct)==0);
    }
};