class Solution {
public:
    int r;
    int row[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
    int col[8] = {1, -1, 1, -1, -2, -2, 2, 2};

    bool isvalid(int i, int j) {
        return (i >= 0 && i < r && j >= 0 && j < r);
    }

    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        r = n;

        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;
        int x1 = knightPos[0] - 1;
        int y1 = knightPos[1] - 1;

        if (x1 == tx && y1 == ty) return 0; // Already at the target

        vector<vector<bool>> visit(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        visit[x1][y1] = true;

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size--) {
                int new_x=q.front().first;
                int new_y=q.front().second;
                q.pop();

                for (int i = 0; i < 8; i++) {
                    int nx = new_x + row[i];
                    int ny = new_y + col[i];

                    if (isvalid(nx, ny) && !visit[nx][ny]) {
                        if (nx == tx && ny == ty) return ans;
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1; // Should never happen on a valid board
    }
};
