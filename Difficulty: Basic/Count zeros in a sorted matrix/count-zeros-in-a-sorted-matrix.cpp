//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        // code here
        int N=A.size();
        int i = 0, j = N - 1;
    int count = 0;

    while (i < N && j >= 0) {
        if (A[i][j] == 0) {
            count += (j + 1); // all left are zeros
            i++; // move to next row
        } else {
            j--; // move left
        }
    }
    return count;
        
    }
};