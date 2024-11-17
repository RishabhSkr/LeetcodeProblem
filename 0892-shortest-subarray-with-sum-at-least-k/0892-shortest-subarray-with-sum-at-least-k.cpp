class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=INT_MAX;
        long long prefix_sum=0;
        deque<pair<long long,long long>> dq;
        //pair-> p_s, index
        dq.push_back({0,-1});
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            while(!dq.empty() && prefix_sum<=dq.back().first){
                dq.pop_back();

            }
            long long checker=prefix_sum-k;

            while(!dq.empty() && checker>=dq.front().first){
                res=min(res,i-dq.front().second);
                dq.pop_front();
            }
            dq.push_back({prefix_sum,i});
        }
        return res!=INT_MAX ? res:-1;
    }
};