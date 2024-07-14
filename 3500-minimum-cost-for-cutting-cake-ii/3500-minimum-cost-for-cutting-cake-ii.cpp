class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hcut, vector<int>& vcut) {
        sort(hcut.begin(),hcut.end(),greater());
        sort(vcut.begin(),vcut.end(),greater());
        long long i = 0,j =0,noHBlock = 1,noVBlock=1;
        long long totalCost = 0;
        while(i<m-1 && j<n-1){
            if(hcut[i]<vcut[j]){
                totalCost+=noHBlock*vcut[j++];
                noVBlock++;
            }else{
                totalCost+=noVBlock*hcut[i++];
                noHBlock++;
            }   
        }
        long long  remCost = 0;
        while(i<m-1){
            remCost +=hcut[i++];
        }
        totalCost+=remCost*noVBlock;
        remCost=0;
        while(j<n-1){
            remCost+=vcut[j++];
        }
        totalCost+=remCost*noHBlock;
        return totalCost;
    
    }
};