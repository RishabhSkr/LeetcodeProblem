class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        // sort the intervals
        sort(intervals.begin(),intervals.end());

        int i =1,n = intervals.size();
        pq.push({intervals[0][1],intervals[0][0]});
        
        for(int i =1;i<n;++i){
            int s = intervals[i][0];
            int e = intervals[i][1];
            int minEnd = pq.top()[0];
            // If the current interval merges with the min group, then it should be added in new group 
			// No need to check with other group intervals, because it merges with all other groups as we're maintaing min heap
            if(s<=minEnd){
                pq.push({e,s});
            }else{
                // Curr interval not merging with min group, then update the group interval
                pq.pop();
                pq.push({e,s});
            }
        }
        return pq.size();
    }
};