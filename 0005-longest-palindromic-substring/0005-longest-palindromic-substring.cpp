class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.length(), maxLength = 1, start = 0, firstOccurrence = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Initialize the diagonal entries as true (single character is a palindrome)
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        if (S[i] == S[i + 1]) {
            dp[i][i + 1] = true;
            if (maxLength < 2) {
                maxLength = 2;
                start = i;
                firstOccurrence = i;
            }
        }
    }

    // Check for palindromes of length greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (S[i] == S[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLength) {
                    maxLength = len;
                    start = i;
                    firstOccurrence = i;
                } else if (len == maxLength && i < firstOccurrence) {
                    firstOccurrence = i;
                }
            }
        }
    }

    return S.substr(firstOccurrence, maxLength);
    }
};