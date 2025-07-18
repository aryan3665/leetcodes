class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int l = nums.size();
        long long inim = 0, iniM = 0;

        priority_queue<int> maxhp;
        priority_queue<int, vector<int>, greater<int>> minhp;

        for (int i = 0; i < l / 3; ++i) {
            inim += nums[i];
            iniM += nums[l - 1 - i];
            maxhp.push(nums[i]);
            minhp.push(nums[l - 1 - i]);
        }

        vector<long long> summ(l / 3 + 1, 0);
        summ[0] = inim;
        summ.back() -= iniM;

        for (int i = l / 3; i < 2 * (l / 3); ++i) {
            int curr = maxhp.top();
            if (curr > nums[i]) {
                maxhp.pop();
                maxhp.push(nums[i]);
                inim -= curr;
                inim += nums[i]; 
            }

            curr = minhp.top();
            if (curr < nums[l - 1 - i]) {
                minhp.pop();
                minhp.push(nums[l - 1 - i]);
                iniM -= curr;
                iniM += nums[l - 1 - i];
            }

            summ[i - l / 3 + 1] += inim;
            summ[2 * (l / 3) - 1 - i] -= iniM;
        }

        return *min_element(summ.begin(), summ.end());
    }
};