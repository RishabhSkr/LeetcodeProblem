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
void insert(BitTrie*root,int num){
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
        int ithBit =(num>>i)&1;
        if(ithBit==0){
            if(node->right!=NULL){
                node =node->right;
                res+=pow(2,i)*1; // 1^0 =1
            }
            else
                node =node->left;
                // res+=pow(2,i)*0;  0^0 =0// not needed because it will zero
        }else{
            if(node->left!=NULL){
                res+=pow(2,i)*1; // 1^0=1
                node=node->left;
            }
            else
                node = node->right;
                //  res+=pow(2,i)*0; // 1^1 =0
            
        }
    }
    return res;
}
    int findMaximumXOR(vector<int>& nums) {
        BitTrie *root =new BitTrie();
        int n =nums.size();
        for(int i =0;i<n;++i){
            insert(root,nums[i]);
        }
        int ans =0;
        for(int i =0;i<n;++i){
             ans = max(ans,findMax(root,nums[i]));
        }
        return ans;
    }
};