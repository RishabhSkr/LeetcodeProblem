class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
    double ans = 0,wt =0;
        wt = cust[0][0]+cust[0][1];
        ans +=wt-cust[0][0];
        int n = cust.size();
        for(int i =1 ;i<n;++i){
            int arr = cust[i][0];
            int time = cust[i][1];
            if(wt<arr){ // if(measn chef is free or cpu is idle)
                wt= arr+time;
                ans+=wt-arr;
            }
            else{
                wt+=time;
                ans+=wt-arr;
            }
        }
        double  res = 1.0*ans/n;
        return res;
    }
};