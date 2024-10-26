class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: one way to form an empty string without any skip
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                // Option 1: Include the current character
                dp[i + 1][j] += dp[i][j];

                // Option 2: Skip the character if not already skipped and it's a duplicate
                if (j == 0 && i > 0 && word[i] == word[i - 1]) {
                    dp[i + 1][1] += dp[i][j];
                }
            }
        }

        // Total possible original strings: ways with or without using a skip
        return dp[n][0] + dp[n][1];
    }
};
