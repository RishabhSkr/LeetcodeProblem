class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& pro, vector<int>& worker) {
        vector<vector<int>>job;
        int n =pro.size();
        for(int i =0;i<n;++i){
            job.push_back({dif[i],pro[i]});
        }
        sort(job.begin(),job.end());
        sort(worker.begin(),worker.end());
        int i=0,maxi =0,ans=0;
        for(auto  power : worker){
            // cout<<job[i][0]<<" "<<job[i][1]<<endl;
            while(i<n && job[i][0]<=power){
                maxi=max(maxi,job[i][1]);
                i++;
            }
            ans+=maxi;
        }
        return ans;
    }
};