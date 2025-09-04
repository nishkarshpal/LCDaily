class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z);
        int dy = abs(y - z);
        if (dx == dy) return 0;   // both reach at the same time
        return dx < dy ? 1 : 2;   // 1 if x is closer, else 2
    }
};