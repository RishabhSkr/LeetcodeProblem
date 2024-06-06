class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        for(auto x: nums)mp[x]++,pq.push(x);
        // for(auto x : mp)pq.push(x.first);
        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();
            if(mp[ele]==0)continue;
            mp[ele]--;
            int remain = k-1;
            while(remain){
                // Check if the current sequence is consecutive
                if(mp[ele+1])remain--,mp[ele+1]--,ele=ele+1;
                else return false;

            }
            
        }
        return true;
    }
};