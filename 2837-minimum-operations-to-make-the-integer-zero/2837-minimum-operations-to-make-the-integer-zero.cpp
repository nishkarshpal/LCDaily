class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 100; k++) {
            long long value = num1 - k * num2;
            if (value < 0)
                break;
            if (value < k)
                continue;
            int bitCount = __builtin_popcountll(value);
            if (bitCount <= k) {
                return k;
            }
        }
        return -1;
    }
};