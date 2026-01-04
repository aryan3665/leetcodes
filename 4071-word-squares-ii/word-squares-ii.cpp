class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        int n = words.size();

        sort(words.begin(), words.end());

        // choose any 4 distinct words
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {

                        vector<string> v = {
                            words[a], words[b], words[c], words[d]
                        };

                        sort(v.begin(), v.end());

                        // check all 24 permutations of chosen 4 words
                        do {
                            string top = v[0];
                            string left = v[1];
                            string right = v[2];
                            string bottom = v[3];

                            if (top[0] == left[0] &&
                                top[3] == right[0] &&
                                bottom[0] == left[3] &&
                                bottom[3] == right[3]) {
                                ans.push_back({top, left, right, bottom});
                            }

                        } while (next_permutation(v.begin(), v.end()));
                    }
                }
            }
        }

        sort(ans.begin(), ans.end()); // lexicographic order
        return ans;
    }
};
