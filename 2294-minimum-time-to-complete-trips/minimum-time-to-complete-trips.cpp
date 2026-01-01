class Solution {
public:
    bool isanswer(vector<int>& time, int totalTrips, long long mid) {
        long long sum = 0;
        for (int i = 0; i < time.size(); i++) {
            sum += mid / time[i];
            if (sum >= totalTrips) return true; // early stop
        }
        return sum >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (isanswer(time, totalTrips, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
