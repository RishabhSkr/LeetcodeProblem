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
#define lli long long int
    bool isBst(TreeNode * root,lli mini,lli maxi){
        if(root==NULL)return true;
        if(root->val<=mini || root->val>=maxi) return false;
        return (isBst(root->left,mini,root->val)& isBst(root->right,root->val,maxi));
    }
    bool isValidBST(TreeNode* root) {
        return isBst(root,-1e18,1e18);
    }
};