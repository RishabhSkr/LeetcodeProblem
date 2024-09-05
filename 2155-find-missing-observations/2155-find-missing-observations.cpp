class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum =0;
        for(auto x : rolls)sum+=x;
        // if(2*sum%(m+n)!=0)return {};
        int x = (mean*(m+n)-sum)/n;
        int y = (mean*(m+n)-sum)%n;
        if(x<=0 || x>6) return {};
        if(x==6 && y>0) return {};
        vector<int>res(n,0);
        for(int i =0;i<n;++i)res[i]=x;
        
        for(int i =0;i<y;++i)res[i]++;
  
        return res;
        
    }
};