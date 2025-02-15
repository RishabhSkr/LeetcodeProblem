class Solution {
public:
    bool solve(int tar,int idx,string &str){
        if(idx==str.size())return tar==0;
        int curr = 0;
        for(int i=idx ;i<str.size();++i){
            curr = curr*10+(str[i]-'0');
            if(curr>tar)break;
            if(solve(tar-curr,i+1,str))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i<=n;++i){
            string str  = to_string(i*i);
            if(solve(i,0,str))ans+=(i*i);
        }
        return ans;
    }
};