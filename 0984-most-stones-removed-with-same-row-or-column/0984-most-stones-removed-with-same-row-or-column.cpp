class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0;i<n;++i)parent[i]=i;
        for(int i =0;i<n;++i)size[i]=1;
    }
    //find parent
    int findUparent(int node){
        if(parent[node]==node)return node;
        return parent[node]= findUparent(parent[node]);
    }
    // Union By size
    void unionBySize(int u,int v){
        int u_parent = findUparent(u);
        int v_parent = findUparent(v);
        if(u_parent==v_parent)return;
        else if(size[u_parent]<size[v_parent]){
            size[v_parent]+=size[u_parent];
            parent[u_parent]=v_parent;
        }else{
            size[u_parent]+=size[v_parent];
            parent[v_parent]=u_parent;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n+1);
        for(int  i =0;i<n;++i){
            for(int j = i+1;j<n;++j){
            // if any two points are on the same column or row, they are connected as a edge.   
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    ds.unionBySize(i,j);
            }
        }
        int groups = 0;
        for(int i =0;i<n;++i){
            if(ds.parent[i]==i)groups++;
        }
        return n-groups;
    }
};