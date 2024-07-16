/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* solve(TreeNode * root,int &src,int &dest){
    if(root== NULL || root->val==src || root->val==dest)return root;
    TreeNode* left = solve(root->left,src,dest);
    TreeNode * right= solve(root->right,src,dest);
    if(left == NULL)return right;
    else if(right ==NULL)return left;
    else return root; // both not null return root;
}

bool pathFind(TreeNode * root,int &value,string&path){
    if(root==NULL)return false;
    if(root->val==value){
        return true;
    }
    path+='L';
    if(pathFind(root->left,value,path)) return true;
    path.pop_back();

    path+='R';
    if(pathFind(root->right,value,path))return true;
    path.pop_back();
    return false;
}
    string getDirections(TreeNode* root, int src, int dest) {
        TreeNode* lca  = solve(root,src,dest);
            string p1 ,p2;
            pathFind(lca,src,p1);
            for(auto &x:p1)x='U';
            pathFind(lca,dest,p2);
            return p1+p2;   
    }
};