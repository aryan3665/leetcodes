class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;

        int l = 0;
        int maxi = 0;

        for (int h = 0; h < fruits.size(); h++) {

            // Add current fruit
            mp[fruits[h]]++;

            // More than 2 types → shrink window
            while (mp.size() > 2) {
                mp[fruits[l]]--;

                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }

                l++;
            }

            // Valid window
            if (mp.size() <= 2) {
                maxi = max(maxi, h - l + 1);
            }
        }

        return maxi;
    }
};