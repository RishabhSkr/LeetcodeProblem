class Solution {
public:
    int findNxtIdx(int i,int duration,vector<int>&days){
        int curr = days[i]+duration-1;
        int nxtIdx = i+1;
        while(nxtIdx<days.size() && days[nxtIdx]<=curr )nxtIdx++;
        return nxtIdx;
    }
    vector<int>dp;
  int solve(int i, vector<int>& days, vector<int>& cost) {
    if (i >= days.size()) return 0;
    if(dp[i]!=-1)return dp[i];
    int nxt1DayIdx = findNxtIdx(i, 1, days);
    int cost1Day = cost[0] + solve(nxt1DayIdx, days, cost); 

    int nxt7DayIdx = findNxtIdx(i, 7, days);
    int cost7Day = cost[1] + solve(nxt7DayIdx, days, cost);

    int nxt30DayIdx = findNxtIdx(i, 30, days);
    int cost30Day = cost[2] + solve(nxt30DayIdx, days, cost);

    return dp[i]=min({cost1Day, cost7Day, cost30Day});
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // state curr idx store min cost store kro
        dp.resize(days.size()+1,-1);
        return solve(0, days, costs);
    }
};