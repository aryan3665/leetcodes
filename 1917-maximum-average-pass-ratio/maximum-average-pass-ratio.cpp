class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda function to compute the gain of adding one extra student
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max heap: stores {gain, {pass, total}}
        priority_queue<pair<double, pair<int,int>>> pq;

        // Initialize heap with all classes
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int pass = top.second.first, total = top.second.second;
            pass++, total++;  // add one extra student
            pq.push({gain(pass, total), {pass, total}});
        }

        // Compute final average ratio
        double sum = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int pass = top.second.first, total = top.second.second;
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};
