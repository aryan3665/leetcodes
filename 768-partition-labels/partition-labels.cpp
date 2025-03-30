class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, -1);
        
        // Store the last index of each character
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int n=s.size();
        int i=0;
        while(i<n){
            int end=v[s[i]-'a'];
            int j=i;
            while(j<end){
                end=max(end,v[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }

        return ans;
    }
};
