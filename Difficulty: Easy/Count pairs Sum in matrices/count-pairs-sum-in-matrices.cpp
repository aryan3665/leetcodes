class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int> elementsOfMat2;

        // Store all elements of mat2 in a set
        for (int i = 0; i < mat2.size(); i++) {
            for (int j = 0; j < mat2[0].size(); j++) {
                elementsOfMat2.insert(mat2[i][j]);
            }
        }

        int count = 0;

        // Check for pairs
        for (int i = 0; i < mat1.size(); i++) {
            for (int j = 0; j < mat1[0].size(); j++) {
                int complement = x - mat1[i][j];
                if (elementsOfMat2.count(complement)) {
                    count++;
                }
            }
        }

        return count;
    }
};
