class Solution {
public:
    int n;
    unordered_map<int, int> mp; // Maps stone value -> its index
    // Memoization table: dp[i][k] = can we reach the end from stone i with last jump k?
    // We use a vector of maps: memo[i] is a map where key is 'k' (prev_jump)
    vector<unordered_map<int, bool>> memo;

    bool solve(vector<int>& stones, int current_stoneidx, int prevjump) {
        // Base case: reached the last stone
        if (current_stoneidx == n - 1) {
            return true;
        }

        // Check if this state is already computed
        if (memo[current_stoneidx].find(prevjump) != memo[current_stoneidx].end()) {
            return memo[current_stoneidx][prevjump];
        }

        bool result = false;
        // Try the next three possible jumps: k-1, k, k+1
        for (int nextjump = prevjump - 1; nextjump <= prevjump + 1; nextjump++) {
            if (nextjump > 0) {
                int next_stone_value = stones[current_stoneidx] + nextjump;
                // Check if a stone exists at this new position
                if (mp.find(next_stone_value) != mp.end()) {
                    int next_stone_index = mp[next_stone_value];
                    // Recursively check if we can reach the end from the next stone
                    result = result || solve(stones, next_stone_index, nextjump);
                    // If result becomes true, we can break early (optional optimization)
                    if (result) break;
                }
            }
        }

        // Store the result for this state before returning
        memo[current_stoneidx][prevjump] = result;
        return result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        // Important check: The first jump must be 1, so the second stone must be at position 1.
        if (stones[1] != 1) return false;

        // Initialize the map: stone value -> index
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        // Initialize the memoization table of size 'n'
        memo.resize(n);

        // Start from stone at index 0, with previous jump = 0
        // (The jump that got us to the first stone is considered 0)
        return solve(stones, 0, 0);
    }
};