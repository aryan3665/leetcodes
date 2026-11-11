class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        int mn = min(need1, need2);

        long long a2 = 1LL * mn * costBoth
                     + 1LL * (need1 - mn) * cost1
                     + 1LL * (need2 - mn) * cost2;

        long long a3 = 1LL * max(need1, need2) * costBoth;

        return min({a1, a2, a3});
    }
};