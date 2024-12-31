class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // state curr idx store min cost store kro
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        int j = 0;
        for (int i = 1; i <= lastDay; ++i) {
            if (i != days[j]) {
                dp[i] = dp[i - 1];
                continue;
            }

            // prev1
            dp[i]=costs[0]+ dp[i-1];
            // 7day
            dp[i] =min(dp[i],costs[1]+(i>=7?dp[i-7]:0));
             // 30day
            dp[i] =min(dp[i],costs[2]+(i>=30?dp[i-30]:0));
            j++;
        }
        return dp[lastDay];

    }
};