class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int numberOfExistingRolls =
            rolls.size(); // The number of existing rolls in the sequence

        // The total sum required to reach the desired mean for all rolls (both
        // existing and missing)
        int totalSumNeeded = (n + numberOfExistingRolls) * mean;

        // Subtract the sum of existing rolls from the total sum needed to find
        // the sum of the missing rolls
        for (int rollValue : rolls) {
            totalSumNeeded -= rollValue;
        }

        // Return an empty vector if the total sum of missing rolls exceeds the
        // max or min possible sum
        if (totalSumNeeded > n * 6 || totalSumNeeded < n) {
            return {};
        }

        // Create the result vector with default values (totalSumNeeded / n)
        vector<int> missingRolls(n, totalSumNeeded / n);

        // Distribute the remaining values (totalSumNeeded % n) evenly across
        // the first few elements
        for (int i = 0; i < totalSumNeeded % n; ++i) {
            ++missingRolls[i];
        }

        // Return the completed vector of missing rolls
        return missingRolls;
    }
};