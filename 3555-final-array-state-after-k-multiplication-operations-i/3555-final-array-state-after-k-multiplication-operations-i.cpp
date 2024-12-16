class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n= nums.size();
        typedef pair<int,int> pii;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i =0;i<n;++i)pq.push({nums[i],i});
        while(k--){
            auto x = pq.top();
            pq.pop();

            int num  = x.first * multiplier;
            int ind = x.second;
            pq.push({num,ind});

        }
        while(!pq.empty()){
            nums[pq.top().second]= pq.top().first;
            pq.pop();
        }
        return nums;
    }
};