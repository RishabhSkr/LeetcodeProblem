class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
   
        string ans = "";
        while(pq.size()>1){
            auto [f1,ch1]=pq.top();pq.pop();
            auto [f2,ch2]=pq.top();pq.pop();
            cout<<f1<<" "<<ch1<<endl;
            cout<<f2<<" "<<ch2<<endl;
            if(f1>=2){
                ans+=ch1;
                ans+=ch1;
                f1-=2;
            }else{
                ans+=ch1;
                f1-=1;
            }
            if(f2>=2 && f2>=f1){
                ans+=ch2;
                ans+=ch2;
                f2-=2;
            }else{
                ans+=ch2;
                f2-=1;
            }
            if(f1>0)pq.push({f1,ch1});
            if(f2>0)pq.push({f2,ch2});
        }
        if(pq.empty())return ans;
        if(pq.top().first>=2){
            ans+=pq.top().second;
            ans+=pq.top().second;
        }else{
            ans+=pq.top().second;
        }
        return ans;
    }
};