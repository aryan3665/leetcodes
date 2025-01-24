class Solution {
public:
   int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int n = prices.size();
        int left[n], right[n];
        int leftmin = prices[0], rightmax = prices[n-1], maxprofit = 0;
        left[0] = 0; right[n - 1] = 0;                                     // because we can't make any profit with just 1 element
        int i,j;
        for(i = 1, j = n-2; i < n, j >= 0; i++, j--){
            leftmin  = min(leftmin, prices[i]);                            // find the minimum price till now
            left[i]  = max(left[i - 1], prices[i] - leftmin);              // max of selling today or skipping (previous max profit)
            rightmax = max(rightmax, prices[j]);                           // find the maximum price to the right
            right[j] = max(right[j + 1], rightmax - prices[j]);            // max of buying today or skipping
        }
        for(int i = 0; i < n; i++){
            maxprofit = max(maxprofit, left[i] + right[i]);
        }
        return maxprofit;
    }
    
    // EG: PRICES = [3,3,5,0,0,3,1,4]
    //     LEFT   = [0,0,2,2,2,2,2,3]
    //     RIGHT  = [2,2,4,4,4,1,0,0]
    //     SUM    = [2,2,6,6,6,3,2,3] 
	//     MAX PROFIT = 6
};