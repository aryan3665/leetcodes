class Solution {
public:
    int r, c, ei, ej;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    bool boundry(int i, int j) {
        return (i == 0 || i == r - 1 || j == 0 || j == c - 1);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        r = maze.size();
        c = maze[0].size();
        ei = entrance[0];
        ej = entrance[1];
        queue<pair<int, int>> q;
        q.push({ei, ej});
        maze[ei][ej] = '+';
        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (boundry(x, y) && !(x == ei && y == ej)) return level;

                for (int k = 0; k < 4; k++) {
                    int nx = x + row[k];
                    int ny = y + col[k];
                    if (isvalid(nx, ny) && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }

        return -1;
    }
};