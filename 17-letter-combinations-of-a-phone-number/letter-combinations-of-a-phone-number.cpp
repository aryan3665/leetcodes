class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result;
        string temp = "";
        solve(0, digits, temp, mp, result);
        return result;
    }

private:
    void solve(int idx, string &digits, string &temp, unordered_map<char,string> &mp, vector<string> &result) {
        if (idx == digits.size()) {
            result.push_back(temp);
            return;
        }
        
        for (char c : mp[digits[idx]]) {
            temp.push_back(c);
            solve(idx + 1, digits, temp, mp, result);
            temp.pop_back(); // backtrack
        }
    }
};
