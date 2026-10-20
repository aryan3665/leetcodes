
class Solution {
public:
    vector<string> ans;
    string temp;
    vector<char> all = {'a', 'b', 'c'};

    void solve(int n) {
        // Base case
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (char c : all) {
            if (temp.empty() || temp.back() != c) {
                temp.push_back(c);
                solve(n);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        ans.clear();
        temp.clear();

        solve(n);

        if (ans.size() < k)
            return "";

        return ans[k - 1];
    }
};
