class Solution {
public:
  
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            
            // count frequencies in current window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            
            // convert to vector for sorting
            vector<pair<int,int>> arr(freq.begin(), freq.end());
            
            // sort by frequency desc, value desc
            sort(arr.begin(), arr.end(), [](auto &a, auto &b){
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            
            // pick top x elements
            int sum = 0;
            int count = 0;
            for (auto &p : arr) {
                if (count == x) break;
                sum += p.first * p.second;
                count++;
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};