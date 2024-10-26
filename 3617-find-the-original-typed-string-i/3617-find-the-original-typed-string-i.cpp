class Solution {
public:
    int n;
    unordered_map<string, int> memo;

    // Helper function to generate a unique key for memoization
    string getKey(int i, char prev, bool skipUsed) {
        return to_string(i) + "-" + prev + "-" + to_string(skipUsed);
    }

    // Recursive function to calculate possibilities
    int solve(int i, string &word, char prev, bool skipUsed) {
        // Base case: reached end of the word
        if (i == n) return 1;

        // Create a unique key for current state
        string key = getKey(i, prev, skipUsed);
        if (memo.find(key) != memo.end()) return memo[key];

        int count = 0;
        
        // Option 1: Include the current character
        count += solve(i + 1, word, word[i], skipUsed);

        // Option 2: Skip the current character if it matches previous and skipUsed is false
        if (skipUsed == false && prev == word[i]) {
            count += solve(i + 1, word, prev, true);
        }

        // Memoize the result
        return memo[key] = count;
    }

    int possibleStringCount(string word) {
        n = word.size();
        memo.clear();
        return solve(0, word, '\0', false);  // Initial call with no previous character and no skip used
    }
};
