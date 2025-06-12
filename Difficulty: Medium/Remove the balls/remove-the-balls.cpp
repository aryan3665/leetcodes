class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<int> s1; // for color
        stack<int> s2; // for radius

        for (int i = 0; i < color.size(); i++) {
            if (!s1.empty() && s1.top() == color[i] && s2.top() == radius[i]) {
                // If top matches current, pop (cancel)
                s1.pop();
                s2.pop();
            } else {
                // Else push current values
                s1.push(color[i]);
                s2.push(radius[i]);
            }
        }

        return s1.size();
    }
};
