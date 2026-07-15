class Solution {
  public:
  int countSubsets(int idx, int remaining_sum, vector<int>& arr, vector<vector<int>>& dp) {
        
        // BASE CASE 1: Agar remaining_sum negative ho jaye, toh ye galat rasta hai
        if (remaining_sum < 0) return 0;

        // BASE CASE 2: Jab saare elements khatam ho jayein
        if (idx == arr.size()) {
            // Agar sum perfectly 0 ban gaya, matlab subset mil gaya!
            if (remaining_sum == 0) return 1;
            return 0;
        }

        // DP CHECK: Agar ye state pehle se calculated hai, toh wahi se return karo
        if (dp[idx][remaining_sum] != -1) {
            return dp[idx][remaining_sum];
        }

        // CHOICE 1: Element ko subset me SHAMIL NAHI KARNA (Exclude / Not Take)
        // Sum wahi rahega, bas agle index par chale jao
        int notTake = countSubsets(idx + 1, remaining_sum, arr, dp);

        // CHOICE 2: Element ko subset me SHAMIL KARNA (Include / Take)
        // Sum me se element ki value ghatao, aur agle index par chale jao
        int take = countSubsets(idx + 1, remaining_sum - arr[idx], arr, dp);

        // Dono choices ke tareeqon ko add karke memoize (save) kar lo
        return dp[idx][remaining_sum] = notTake + take;
    }
    int totalWays(vector<int>& arr, int target) {
    int totalSum = 0;
        for (int num : arr) totalSum += num;

        // --- EDGE CASES (Bohat Zaruri Hain!) ---
        
        // Edge Case 1: Agar pure array ka sum hi target se chota hai, toh target banana impossible hai.
        if (totalSum < abs(target)) return 0;
        
        // Edge Case 2: Agar (totalSum + target) odd  hai, toh integer division me points me 
        // answer aayega (jaise 7/2 = 3.5). Kisi subset ka sum decimal me nahi ho sakta, isiliye return 0.
        if ((totalSum + target) % 2 != 0) return 0;

        // Humara naya Target Sum (S1) calculate karo
        int S1 = (totalSum + target) / 2;

        int n = arr.size();
        
        // DP Matrix Setup:
        // Rows: 0 se n (elements track karne ke liye)
        // Columns: 0 se lekar S1 tak (naye target sum ko track karne ke liye)
        vector<vector<int>> dp(n + 1, vector<int>(S1 + 1, -1));

        // Recursion call karenge index 0 aur naye target S1 ke sath
        return countSubsets(0, S1, arr, dp);
}
        
    
};