class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>temp;
        int n=profits.size();
        for(int i =0;i<n;++i){
            temp.push_back({profits[i],capital[i]});
        }
        sort(temp.begin(),temp.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])return a[0]>b[0];
            return a[1]<b[1];
         });
        priority_queue<int>pq;
        int i =0;
       while(k--){
            while(i<n&& temp[i][1]<=w){
                pq.push(temp[i][0]);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};