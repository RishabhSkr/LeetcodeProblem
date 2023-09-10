//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public: 
    vector<int>parent,rank,size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i =0 ;i<=n; ++i){
            parent[i]=i;
            size[i] = 1;
        }
        
    }
    int findUpar(int node ){
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionFindByRank(int u,int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        if(ult_u==ult_v)return ;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_u]>rank[ult_v]){
            rank[ult_v]=ult_u;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
        
    }
    
    void UnionFindBySize(int u ,int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        if(ult_u==ult_v)return ;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
       
        else{
            parent[ult_v]=ult_u;
           size[ult_u]+=size[ult_v];
        }
        
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        DisjointSet ds(n);
      
        // step 1: indexing maping string name  to int and creating node and joining set
        unordered_map<string,int>mapMailNode;
        
        for(int i = 0 ;i<n;++i){
            for(int j =1; j<accounts[i].size(); ++j){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }else{
                    // if  already map means node has to merge 
                    ds.UnionFindBySize(i,mapMailNode[mail]);
                }
            }
        }
        
        // step 2: merging
        vector<string>mergeMail[n];
        for(auto it: mapMailNode){
            string  mail = it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }
        
        
        // step3: remapping and store it in ans in sorted order
        vector<vector<string>> ans;
        
        for(int i =0 ;i<n ;i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends