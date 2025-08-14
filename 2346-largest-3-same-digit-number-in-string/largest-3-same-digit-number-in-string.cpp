class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int> ans;
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string sub = num.substr(i, 3);
                ans.push_back(stoi(sub)); // convert to int and store
            }
        }

        if (ans.empty()) return "";

        int maxi = *max_element(ans.begin(), ans.end());
        string res = to_string(maxi);

        // If it's "0", "00", or "000", we still need exactly 3 digits
        while (res.size() < 3) res = "0" + res;

        return res;
    }
};
