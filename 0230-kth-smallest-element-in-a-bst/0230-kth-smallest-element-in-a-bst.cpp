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
    void solve(TreeNode * root,int k,vector<int>&kth){
        if(root==NULL)return ;
        if(kth.size()==k)return;
        solve(root->left,k,kth);
        kth.push_back(root->val);
        solve(root->right,k,kth);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>kth;
        solve(root,k,kth);
        return kth[k-1];
    }   
};