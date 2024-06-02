class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>ans;
        ans.push_back({meetings[0][0],meetings[0][1]});
        int e =meetings[0][1];
        int n = meetings.size();
        for(int i = 1;i<n;++i){
            if(ans.back()[1]>=meetings[i][0])ans.back()[1]=meetings[i][1];
            else ans.push_back(meetings[i]);
            e = max(meetings[i][1],e);
            ans.back()[1]=e;
            // cout<<meetings[i][0]<<" "<<meetings[i][1]<<endl;
            // cout<<"ans arrays "<<ans.back()[0]<<" "<<ans.back()[1]<<endl;
        }
        int res = 0;
        for(int i =0;i<ans.size();++i){
            res+=ans[i][1]-ans[i][0]+1;
        }
        return days-res;
    }
};