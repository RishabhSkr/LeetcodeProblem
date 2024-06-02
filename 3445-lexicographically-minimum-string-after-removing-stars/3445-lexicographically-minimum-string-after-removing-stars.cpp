class Solution {
public:
struct compare{
    bool operator()(pair<char,int>&a,pair<char,int>&b){
         if(a.first==b.first){
            return a.second<b.second;
        }
    return a.first>b.first;
    }
};

    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        int n = s.length();
        for(int i =0;i<n;++i){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }else{
                if(!pq.empty()){
                    auto x = pq.top();
                    s[x.second]='*';
                    pq.pop();
                }
            }
        }
        cout<<s<<endl;
        string ans = "";
        int i = 0;
        while(i<s.length()){
           if(s[i]!='*')ans+=s[i];
           i++;
        }
        return ans;
    }
};