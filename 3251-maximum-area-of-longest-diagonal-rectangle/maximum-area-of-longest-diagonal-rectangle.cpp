class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        // map: index -> {diagonal, area}
        map<int, pair<double,int>> mp;

        for (int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            double diag = sqrt(1.0 * l * l + 1.0 * w * w);
            int area = l * w;

            mp[i] = {diag, area};
        }

        double maxDiag = -1;
        int maxArea = -1;

        // iterate over map and find max
        for (auto &it : mp) {
            double diag = it.second.first;
            int area = it.second.second;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } 
            else if (fabs(diag - maxDiag) < 1e-9 && area > maxArea) {
                // same diagonal length, but bigger area
                maxArea = area;
            }
        }

        return maxArea;
    }
};
