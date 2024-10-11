class Solution {
public:
        // // Plan-> sort times acc to arr 
        // // pq => {chairNo,arr,end},chairNo -> 0,1,2...infinity
        // // use  two min heaps-> store one with 
        // sort(times.start(),times.end(),[](vector<int>&a,vector<int>&b){
        //     return a[0]<b[0];
        // });
        // // two min for searching
        // priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq1,pq2;
        // int chair=0;
        // for(auto time : times){
        //     int s = time[0];
        //     int e = time[1];
        //     if(!pq1.empty()){
        //         auto top = pq1.top();
        //         int chairNo = top.first;
        //         auto start = top.second[0];
        //         auto end = top.second[1];
        //         pq.pop();
        //         if(end<=s){

        //         }
        //     }
        //     pq1.push({chair++,{s,e}});
        // }
        // while(!pq1.empty()){
        //     int chairNo = top.first;
        //     int arr
        // }
        
    int smallestChair(vector<vector<int>>& times, int tar) {
        // brute force ->O(n^2) S.C->O(n)
        /*
            plan->
                -sort the times based on arr time
                -store the dep time on each chair
                - For each friend in time traverse the chair and look for chair whose deadline is complete
                - Look for the chair whose dept time is finished assing it and search for target friend
        */
        int n=times.size();
        int tarArr = times[tar][0]; // because time of arr is unique

        sort(times.begin(),times.end());
        vector<int>chair(n,-1);

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
        return -1;
    }
};