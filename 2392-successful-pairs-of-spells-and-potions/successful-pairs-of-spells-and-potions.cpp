class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++) {
            long long spell = spells[i];

            // minimum potion needed
            long long mini = (success + spell - 1) / spell; // safer than ceil(double)

            if (mini > potions[n - 1]) {
                ans.push_back(0);
                continue;
            }

            int index = lower_bound(potions.begin(), potions.end(), mini) - potions.begin();
            ans.push_back(n - index);
        }

        return ans;
    }
};
