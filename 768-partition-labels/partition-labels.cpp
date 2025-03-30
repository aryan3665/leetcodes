class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, 0);
        
        // Store the last index of each character
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int i = 0, j = 0;
        int n = s.size();
        
        while (j < n) {
            int end = v[s[j] - 'a'];

 
            while (j <= end) {
                end = max(end, v[s[j] - 'a']);
                j++;
            }

            
            ans.push_back(j - i);
            i = j;
        }

        return ans;
    }
};
