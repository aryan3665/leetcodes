
class Solution {
public:
    vector<string> ans;
    vector<string> all = {"a", "b", "c"};
    string temp;
int p;
    void solve(int n) {
        // Base case

        if(ans.size()==p)return;
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (temp.empty() || temp.back() != all[i][0]) {
                temp.push_back(all[i][0]);

                solve(n);

                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        ans.clear();
        temp.clear();
        p=k;

        solve(n);

        if (ans.size() < k)
            return "";

        return ans[k - 1];
    }
};
