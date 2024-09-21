
class Solution {
public:
vector<int>res;
   void solve(int n,int curr){
        if(curr>n)return ;
        res.push_back(curr);
        for(int no=0;no<=9;no++){
            int nxt =curr*10+no;
            if(nxt<=n){
                solve(n,nxt);
            }else break;
        }
   }
    vector<int> lexicalOrder(int n) {
        for(int i = 1;i<=9;++i){
            solve(n,i);
        }
        return res;
    }
};