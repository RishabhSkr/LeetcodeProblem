class Solution {
public:
       
        // brute force ->O(n^2) S.C->O(n)
        /*
            plan->
                -sort the times based on arr time
                -store the dep time on each chair
                - For each friend in time traverse the chair and look for chair whose deadline is complete
                - Look for the chair whose dept time is finished assing it and search for target friend
        for(auto t : times){
            int arr = t[0];
            int dept = t[1];
            for(int i=0;i<n;++i){
               
                if(chair[i]<=arr){
                    chair[i]=dept;
                    if(arr==tarArr)return i;
                    // assign ek me ho gya exit kr jaao
                    break;
                }
                
            }
        }
        */
        // Optimal->O(nLogn) Plan-> sort times acc to arr searching for each frnd chair taking n times how about decrease it in logn and or less.
        // pq => {chairNo,arr,end},chairNo -> 0,1,2...infinity
        // use  two min heaps-> store one with 
    typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int tar) {
        int n=times.size();
        int tarArr = times[tar][0]; // because time of arr is unique

        sort(times.begin(),times.end());

        // two min for searching
        priority_queue<P,vector<P>,greater<P>>pq1;
        priority_queue<int>pq2;
        int cnt = 0;

        for(auto time : times){
            int s = time[0];
            int dept = time[1];
            

            while(!pq1.empty() && pq1.top().first<=s){
                auto chairInd = pq1.top().second;
                pq2.push(-1*chairInd);
                pq1.pop();
            }
            if(pq2.empty()){
                pq1.push({dept,cnt});
                if(s==tarArr)return cnt;
                cnt++;
            }
            else{
                int smallChair = -1*pq2.top();
                pq2.pop();
                if(s==tarArr)return smallChair;
                pq1.push({dept,smallChair});
            }
        }

        return -1;
    }
};