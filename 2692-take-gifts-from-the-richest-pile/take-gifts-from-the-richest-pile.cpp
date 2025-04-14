#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // for sqrt and floor

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::priority_queue<int> p;
        
        for (int gift : gifts) {
            p.push(gift);
        }

        for (int i = 0; i < k; i++) {
            int k1 = p.top();
            p.pop();
            int reduced = (int)std::floor(std::sqrt(k1));
            p.push(reduced);
        }

        long long sum = 0;
        while (!p.empty()) {
            sum += p.top();
            p.pop();
        }

        return sum;
    }
};
