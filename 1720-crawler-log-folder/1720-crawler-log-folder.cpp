class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto str : logs){
            if(str=="../" && cnt>0)cnt--;
            else if(str!="./" && str!="../")cnt++;
            else ;
            cout<<cnt<<endl;
        }
        return cnt;
    }
};