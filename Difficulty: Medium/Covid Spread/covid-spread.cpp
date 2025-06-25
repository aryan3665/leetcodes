class Solution {
  public:
    bool valid(int i, int j, int r, int c) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    int helpaterp(vector<vector<int>> hospital) {
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};

        int r = hospital.size();
        int c = hospital[0].size();
        queue<pair<int, int>> q;

        // Push all infected patients
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (hospital[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;

        while (!q.empty()) {
            int curr_patient = q.size();
            bool spread = false;

            while (curr_patient--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (valid(ni, nj, r, c) && hospital[ni][nj] == 1) {
                        hospital[ni][nj] = 2;
                        q.push({ni, nj});
                        spread = true;
                    }
                }
            }

            if (spread) time++; // Only increment time if infection spread this round
        }

        // Check for any uninfected patient
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (hospital[i][j] == 1) return -1;
            }
        }

        return time;
    }
};
