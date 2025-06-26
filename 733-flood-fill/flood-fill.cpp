class Solution {
public:
    int r, c;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();

        int startColor = image[sr][sc];
        if (startColor == color) return image; 

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            int new_i = q.front().first;
            int new_j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = new_i + row[k];
                int nj = new_j + col[k];

                if (valid(ni, nj) && image[ni][nj] == startColor) {
                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }

        return image;
    }
};
