class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        // Storing elements in the map as both key and value
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = nums[i];  
        }

        int longestStreak = 0;

        // Checking for the longest consecutive sequence
        for (auto it : mp) {
            if (mp.find(it.first - 1) == mp.end()) { // Start of a sequence
                int currentNum = it.first;
                int currentStreak = 1;

                while (mp.find(currentNum + 1) != mp.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
