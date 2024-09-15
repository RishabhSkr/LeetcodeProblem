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
    TreeNode *prev = NULL;
    // preorder traversal
 // T.C O(n),S.C ->O(n)
    void solve(TreeNode* root){
        if(root==NULL )return;

        TreeNode*rhead =root->right;
        if(prev!=NULL){  // 3 node ka tree trace kro solve ho jaega 
            prev->right = root;
            prev->left =NULL;
        }
        prev = root;
        solve(root->left);
        solve(rhead);
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};