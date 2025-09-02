class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        // Sort points by x, then by y (descending) so that for same x, higher y
        // comes first.
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // same x: higher y first
                 return a[0] < b[0];
             });

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if points[i] is top-left and points[j] is bottom-right?
                // So points[i].x <= points[j].x and points[i].y >= points[j].y.
                if (points[i][0] <= points[j][0] &&
                    points[i][1] >= points[j][1]) {
                    bool valid = true;
                    // Check all other points are not inside the rectangle.
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;
                        if (points[k][0] >= points[i][0] &&
                            points[k][0] <= points[j][0] &&
                            points[k][1] <= points[i][1] &&
                            points[k][1] >= points[j][1]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                        count++;
                }
            }
        }
        return count;
    }
};