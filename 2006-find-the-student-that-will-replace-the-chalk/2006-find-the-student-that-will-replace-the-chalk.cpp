class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int numStudents = chalk.size();
        vector<long long> prefixSum(numStudents, chalk[0]); //prefixsum
        for (int i = 1; i < numStudents; ++i) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }
        k = k % prefixSum[numStudents - 1]; //modulo
        return std::upper_bound(prefixSum.begin(), prefixSum.end(), k) -
               prefixSum.begin(); //binarysearch
    }
};