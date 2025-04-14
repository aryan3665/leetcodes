class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for (int i = 0; i < stones.size(); i++) {
            p.push(stones[i]);
        }
        while (p.size() > 1) {
            int k1 = p.top();
            p.pop();
            int k2 = p.top();
            p.pop();
            if (k1 != k2) {
                p.push(k1 - k2);
            }
        }
        return p.empty() ? 0 : p.top();
    }
};