class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const pair<double, pair<int, int>>& a,
                      const pair<double, pair<int, int>>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>, decltype(cmp)>
            pq(cmp);
        for (const auto& cls : classes) {
            int pass = cls[0];
            int total = cls[1];
            double current = (double)pass / total;
            double new_ratio = (double)(pass + 1) / (total + 1);
            double improvement = new_ratio - current;
            pq.push({improvement, {pass, total}});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;

            pass++;
            total++;
            double current = (double)pass / total;
            double new_ratio = (double)(pass + 1) / (total + 1);
            double new_improvement = new_ratio - current;

            pq.push({new_improvement, {pass, total}});
        }
        double total_ratio = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            total_ratio += (double)pass / total;
        }

        return total_ratio / classes.size();
    }
};