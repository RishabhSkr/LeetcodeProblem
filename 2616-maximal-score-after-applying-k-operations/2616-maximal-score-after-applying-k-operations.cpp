class Solution {
public:
    #define ll long long
    long long maxKelements(vector<int>& nums, int k) {
        // pq element ko insert kro(max heap)
        // pick one top ele do operation insert in the pq
        // add the picked score
        priority_queue<int>pq;
        ll ans =0;
        for(auto x : nums)pq.push(x);

        while(!pq.empty()){
            double ele =pq.top(); // one reduced to 1 change the data type
            ans+=ele;
            pq.pop();
            pq.push(ceil(ele/3));
            k--;
            if(k==0)break;
        }
        return ans;
    }
};