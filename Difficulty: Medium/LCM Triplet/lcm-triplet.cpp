class Solution {
  public:
    int lcmTriplets(int n) {
        if (n < 3){
            return n; // for n = 1, 1 is the answer and for n=2, 2 is the answer
        }
        if (n % 2){
            return n*(n-1)*(n-2);
        }
        else{
            if (n % 3) return n*(n-1)*(n-3);
            else return (n-1)*(n-2)*(n-3);
        }
    }
};