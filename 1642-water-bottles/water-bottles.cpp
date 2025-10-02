class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int q=99999,r=99999;
        // long sum=0;
        // while(q+r>=numExchange){
        //     q=numBottles/numExchange;
        //     sum=sum+numBottles+q;
        //     r=q%numExchange;
        // }
        // return sum;
        int total = numBottles;  // initially drink all
        int empty = numBottles;  // now you have all empty bottles

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;  // bottles you get by exchange
            total += newBottles;                  // drink them
            empty = empty % numExchange + newBottles; // remaining empty bottles
        }

        return total;
    }
};