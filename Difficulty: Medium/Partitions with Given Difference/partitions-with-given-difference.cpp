class Solution {
  public:
  int countSubsets(int idx, int remaining_sum, vector<int>& arr, vector<vector<int>>& dp) {
        // BASE CASE 1: Agar target sum negative ho gaya, toh ye rasta galat hai
        if (remaining_sum < 0) return 0;

        // BASE CASE 2: Jab saare elements process ho chuke hon
        if (idx == arr.size()) {
            // Agar remaining_sum perfectly 0 hai, matlab ek valid subset mil gaya!
            if (remaining_sum == 0) return 1;
            return 0;
        }

        // DP CHECK: Agar ye state pehle se calculated hai, toh repeat mat karo
        if (dp[idx][remaining_sum] != -1) {
            return dp[idx][remaining_sum];
        }

        // CHOICE 1: Element ko subset me NAHI LENA (Exclude)
        int notTake = countSubsets(idx + 1, remaining_sum, arr, dp);

        // CHOICE 2: Element ko subset me LENA (Include)
        int take = countSubsets(idx + 1, remaining_sum - arr[idx], arr, dp);

        // Dono paths ka sum save karke return karo
        return dp[idx][remaining_sum] = notTake + take;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        // --- EDGE CASES (Wahi purane wale) ---
        
        // Edge Case 1: Agar array ka total sum hi difference 'd' se chota hai, 
        // toh partition banana impossible hai.
        if (totalSum < d) return 0;
        
        // Edge Case 2: Agar (totalSum + d) odd hai, toh split points me aayega.
        // Array numbers integers hain, toh points me subset sum nahi ho sakta.
        if ((totalSum + d) % 2 != 0) return 0;

        // Humara naya Target Subset Sum (S1) calculate karo
        int S1 = (totalSum + d) / 2;

        int n = arr.size();
        
        // DP Table Setup
        vector<vector<int>> dp(n + 1, vector<int>(S1 + 1, -1));

        // Function call: index 0 aur target S1 ke sath
        return countSubsets(0, S1, arr, dp);
    }
};