class Solution {
public:
    bool ispossible(vector<int>& ranks, int cars, long long mid) {
        long long s = 0;
        for (int i = 0; i < ranks.size(); i++) {
            s += sqrt(mid / ranks[i]);
            if (s >= cars) return true; 
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r = (long long) (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long result = -1;
        
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (ispossible(ranks, cars, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};