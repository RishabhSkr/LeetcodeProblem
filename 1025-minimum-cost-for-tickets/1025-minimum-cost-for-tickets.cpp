class Solution {
public:
    
    vector<int>dp;
    unordered_map<int,int>mp;
  int solve(int day, vector<int>& days, vector<int>& cost) {
    if(day>365)return 0;
    if(dp[day]!=-1)return dp[day];
    if(mp.count(day)==0)return dp[day]=solve(day+1,days,cost);
    int cost1Day = cost[0] + solve(day+1, days, cost); 

    int cost7Day = cost[1] + solve(day+7, days, cost);

    int cost30Day = cost[2] + solve(day+30, days, cost);

    return dp[day]=min({cost1Day, cost7Day, cost30Day});
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // state curr idx store min cost store kro
       // Mark travel days in map
        for(int day : days) {
            mp[day] = 1;  // value doesn't matter, we just need to know if day exists
        }
        dp.resize(366,-1);
        return solve(days[0], days, costs);
    }
};