class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 0;
        priority_queue<vector<int>>pq;
        int maxi = 0;
        for(int i =0;i<n;++i){
            int s = arr[i][0];
            int e = arr[i][1];
            int val = arr[i][2];
            // curr iterval choose kro or priority que me dekho curr se pahle khtm hone wale interval me jo max hga usko whi max ans dega
            while(!pq.empty() && -1*pq.top()[0]<s){ // sare event to khtm krte jana h isiliye if nhi lagega
                maxi = max(maxi,pq.top()[1]);
                pq.pop();
            }
            ans= max(maxi+val,ans);
            pq.push({-1*e,val});
            
        }
        return ans ;
    }
};