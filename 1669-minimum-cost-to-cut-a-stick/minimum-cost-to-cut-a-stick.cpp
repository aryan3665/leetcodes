class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& t) {
        if (i > j) return 0;
        if (t[i][j] != -1) return t[i][j];

        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++) {
            int cost = (cuts[j + 1] - cuts[i - 1]) 
                       + f(i, ind - 1, cuts, t) 
                       + f(ind + 1, j, cuts, t);
            mini = min(mini, cost);
        }

        return t[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int l = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> t(l + 2, vector<int>(l + 2, -1));
        return f(1, l, cuts, t);
    }
};
