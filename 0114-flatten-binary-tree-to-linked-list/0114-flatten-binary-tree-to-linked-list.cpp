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
 // T.C O(n),S.C ->O(1)
    void morrisTravesal(TreeNode* root){
        TreeNode * curr = root;
        while(curr!=NULL){
            // find pred
            if(curr->left!=NULL){
                TreeNode * pred = curr->left;
                while(pred->right!=NULL){
                    pred=pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;

            }
            curr=curr->right;
        }
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        morrisTravesal(root);
    }
};