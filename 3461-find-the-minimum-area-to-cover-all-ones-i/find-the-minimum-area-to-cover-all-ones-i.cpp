class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         // iss problem ko solve karne ke liye jo meri approch hai ki hmm 4
        // variable le lete hai start row start col and end row end col and
        // start row me minimu row jaha se first 1 mila usko l=rakhenege same
        // with start col and end row and end col me lasr one kaha mila hai usko
        // rakhenege then area of rectangle aa jayega
        int n = grid.size();
        int m = grid[0].size();
        
        int start_row = n, start_col = m;
        int end_row = -1, end_col = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start_row = min(start_row, i);
                    start_col = min(start_col, j);
                    end_row = max(end_row, i);
                    end_col = max(end_col, j);
                }
            }
        }

        if (end_row == -1) return 0; // agar grid me koi 1 nahi mila

        int l = (end_row - start_row + 1);
        int w = (end_col - start_col + 1);
        return l * w;
    }
};
