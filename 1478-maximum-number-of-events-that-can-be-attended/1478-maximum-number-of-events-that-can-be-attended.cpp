class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // [[1,2],[2,3],[3,4],[1,2]]
        // (1,2) (1,2),(2,4),(3,4)
      //Day  1     2      3     4 -> max meet

       // Sort events by start day, and then by end day if start days are equal
        sort(events.begin(),events.end(),[&](auto a , auto b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        int day =-1,res =0,n = events.size(),idx = 0;

         // Min-heap to store event end days
        priority_queue<int,vector<int>,greater<int>>pq;

        while(!pq.empty() || idx<n){
            // this will lead to out of bound error 
            // int s= because upr or condition
            // int e=

            // Move to the next available day if the priority queue is empty
            if(pq.empty())day = events[idx][0];;

            // Push all events that can start on or before the current day
            while(idx<n && events[idx][0]<=day){
                pq.push(events[idx][1]);
                idx++;
            }
            
            // Attend the event that ends the earliest
            pq.pop();
            res++;  // Increment result for attending one event
            day++;  // Move to the next day

             // Remove all events from the queue that have already ended
            while(!pq.empty() && day>pq.top())pq.pop();
        }
        return res;
    }
};