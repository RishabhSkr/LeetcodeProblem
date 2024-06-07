class Solution {
public:
    // int linearSearch(int i,vector<vector<int>>&job){
    //     int latestNonConflictInd = -1;
    //     for(int j = i-1;j>=0;--j){  // linear search give TLE use BIN SEARCH
    //             if(job[j][0]<=job[i][1]){
    //                 latestNonConflictInd = j;
    //                 break;
    //             }
    //     }
    //     return latestNonConflictInd;
    // }
    int BinSearch(int i, vector<vector<int>>& job) {
        int index = -1;
        int s = 0, e = i - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            // end time of mid job <= start time of ith job
            if (job[mid][0] <= job[i][1]) {
                index = mid;
                s = mid + 1; // look for a later job
            } else {
                e = mid - 1;
            }
        }
        return index;
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<vector<int>>job;
        int n = start.size();
        for(int i=0;i<n;++i){
            job.push_back({end[i],start[i],profit[i]});
        }
        // sort on the basis of ending time
        sort(job.begin(),job.end());
        vector<int>dp(n,0);
        dp[0]=job[0][2];
        for(int i =1;i<n;++i){
            // find latest non-confilicting job index (0 to j-1)
            int take = job[i][2];
            int nonConflictInd =BinSearch(i,job);
            if(nonConflictInd!=-1){
                take+=dp[nonConflictInd];
            } // notTake (take,prevProfit)
            dp[i]= max(dp[i-1],take);
        }
        return dp[n-1];
    }
};