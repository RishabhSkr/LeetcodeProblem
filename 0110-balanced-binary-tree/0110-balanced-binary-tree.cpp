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
    int solve(TreeNode* root,bool &valid){
         if(root==NULL)return 0;
        int l = solve(root->left,valid);
        int r = solve(root->right,valid);
        if(abs(l-r)>1)valid = 0;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool valid = 1;
        solve(root,valid);
        return valid;
    }
};