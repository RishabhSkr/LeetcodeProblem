class Solution {
public:

struct BitTrie{
    BitTrie *left;// 0
    BitTrie *right;//1
    BitTrie(){
        left =NULL;
        right=NULL;
    }
};
void insert(BitTrie*root,int num){  // inset every bit of num in trie whwre nums[i]< mi
    BitTrie *node = root;
    for(int ith =31;ith>=0;--ith){
        int ithBit =(num>>ith)&1;
        if(ithBit ==0){//leftside
            if(node->left==NULL){
                node->left =new BitTrie();
            }
            node=node->left;
        }else{
             if(node->right==NULL){
                node->right =new BitTrie();
            }
            node=node->right;
        }

    }
}
int findMax(BitTrie *root,int num){
    BitTrie *node = root;
    int res =0;
    for(int i=31;i>=0;--i){
        int ithBit =(num>>i)&1; // get ith bit valueby taking bitwise and
        if(ithBit==0){
            if(node->right!=NULL){
                node =node->right;
                res+=(1<<i); // 1^0 =1 // use bitwise shift instead of pow(2,i)*1 for efficiency
            }
            else if(node->left!=NULL){
                // res+=pow(2,i)*0;  0^0 =0// not needed because it will zero
                node =node->left;
            }else break; // If both left and right are NULL, we can't proceed further

        }else{
            if(node->left!=NULL){
                res+=(1<<i); // 1^0=1 // use bitwise shift instead of pow(2,i)*i for efficiency
                node=node->left;
            }
            else if(node->right!=NULL)node= node->right;//  res+=pow(2,i)*0; // 1^1 =0
            else break;// If both left and right are NULL, we can't proceed further

        }
    }
    return res;
}
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        BitTrie *root = new BitTrie();
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();++i){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        int index =0;
        vector<int>res(queries.size(),-1);
        // for all queries insert nums which is less than nums[i]<=mi
        // for this we need to sort the queries and nums, so that it is easy to maintain increasing order
        //Now all nums<mi inserted in trie Now find max xor value with xi for all nums<mi
        // if atleast one nums is inserted in trie index wil >=1 hence find maxXor else ans =-1
        // Since queries is sorted correct pos of ans for queries will be disturbed hence store index of ith query in queries
        // finally return ans;
        for(auto q:queries){
            int xi =q[0];
            int mi =q[1];
            int ind=q[2];
            while(index<nums.size() && nums[index]<=mi){
                insert(root,nums[index]);
                index++;
            }
             // If no numbers <= mi were inserted, result should be -1 
            if(index>0){ // atleast 1 num is inserted in trie index>0 index==0 is inserted
                int ans = findMax(root,xi);
                res[ind]=ans;
            }
        }
        return res;
    }
};