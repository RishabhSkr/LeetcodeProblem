class Solution {
public:
#define ll long long
    int m, n;

    long long maxPoints(vector<vector<int>>& points) {
        m = points.size();
        n = points[0].size();

        vector<ll> prev(n, 0);

        // Initialize prev with the first row values
        for (int col = 0; col < n; ++col) {
            prev[col] = points[0][col];
        }
        
        for (int i = 1; i < m; ++i) {
            vector<ll> left(n, 0), right(n, 0);

            // Compute max values from the left
            left[0] = prev[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            // Compute max values from the right
            right[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            // Compute current row max points
            vector<ll> curr(n, LLONG_MIN);
            for (int j = 0; j < n; ++j) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }

            prev = curr;
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();