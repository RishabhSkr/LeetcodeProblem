class Solution {
public:
    vector<int> solve(const string &s, int i, int j) {
        if (i > j) return {};

        vector<int> res;
        // Iterate between i and j, not the whole string
        for (int k = i; k <= j; ++k) {
            if (s[k] == '-' || s[k] == '+' || s[k] == '*') {
                vector<int> leftRes = solve(s, i, k - 1);
                vector<int> rightRes = solve(s, k + 1, j);

                // Combine results from left and right expressions
                for (int num1 : leftRes) {
                    for (int num2 : rightRes) {
                        if (s[k] == '+') {
                            res.emplace_back(num1 + num2);
                        } else if (s[k] == '-') {
                            res.emplace_back(num1 - num2);
                        } else if (s[k] == '*') {
                            res.emplace_back(num1 * num2);
                        }
                    }
                }
            }
        }

        // If no operator found, it's a number, so convert the substring from i to j
        if (res.empty()) {
            res.emplace_back(stoi(s.substr(i, j - i + 1)));
        }
        return res;
    }

    vector<int> diffWaysToCompute(string exp) {
        return solve(exp, 0, exp.size() - 1);
    }
};
