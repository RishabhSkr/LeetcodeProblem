class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n =original.size();
        vector<vector<long long >>mat(26,vector<long long>(26,LLONG_MAX));

        for(int i =0;i<n;++i){
            int org = original[i]-'a';
            int change = changed[i]-'a';
            mat[org][change]=min((long long)cost[i],mat[org][change]);
        }

        for(int via = 0;via<26;++via){
            for(int i =0;i<26;++i){
                for(int  j = 0;j<26;++j){
                    if(mat[i][via]!=LLONG_MAX && mat[via][j]!=LLONG_MAX)
                        mat[i][j]= min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        long long  minCost =0;
        for(int i =0;i<source.size();++i){
            
                int src = source[i]-'a';
                int dest = target[i]-'a';
                if(src==dest)continue;
                if(mat[src][dest]==LLONG_MAX)return -1;
                minCost+=mat[src][dest];
            
        }
        return minCost;
    }

    
};