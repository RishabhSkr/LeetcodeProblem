class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) {
        vector<vector<int>>meet;
        for(auto x:inter)meet.push_back(x);
        meet.push_back({newinter[0],newinter[1]});
        sort(meet.begin(),meet.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        vector<vector<int>>ans;
        for(auto x : meet){
            int start = x[0];
            int end =x[1];
            if(ans.size()==0)ans.push_back({start,end});
            else{
                if(ans.back()[1]>=start){
                    ans.back()[1]=max(ans.back()[1],end);

                }else{
                    ans.push_back({start,end});
                }
            }
        }
        return ans;


    }
};