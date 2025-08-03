#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long mini = std::numeric_limits<long long>::max(); // Equivalent to python's float("inf") for finding a minimum

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Use long long for costs to avoid overflow during addition
                long long land_cost = (long long)landStartTime[i] + landDuration[i];
                long long water_cost = (long long)waterStartTime[j] + waterDuration[j];

                // Case 1: Land ride first, then water ride
                long long case1 = land_cost + std::max(0LL, (long long)waterStartTime[j] - land_cost) + waterDuration[j];
                
                // Case 2: Water ride first, then land ride
                long long case2 = water_cost + std::max(0LL, (long long)landStartTime[i] - water_cost) + landDuration[i];

                // Update the overall minimum finish time with the minimum of the current two cases
                mini = std::min({mini, case1, case2});
            }
        }
        
        return (int)mini; // Return the earliest finish time found, cast to int
    }
};