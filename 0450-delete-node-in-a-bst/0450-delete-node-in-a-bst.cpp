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
    TreeNode* deleteNode(TreeNode* root, int data) {

        if(root==NULL)return NULL; 
        if(root->val > data){
            root->left=deleteNode(root->left,data);
        }
        else if(root->val < data){
            root->right=deleteNode(root->right,data);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL){
                  TreeNode* tmp = root->right;
                    root->right=NULL;
                    delete root;
                    return tmp;
            }
            else if(root->right==NULL){
                    TreeNode * tmp = root->left;
                    root->left=NULL;
                    delete root;
                    return tmp;
            }else{
                TreeNode * minRight= root->right;
                while(minRight->left!=NULL){
                    minRight=minRight->left;
                }

                int minData= minRight->val;
                root->val=minData;
                root->right=deleteNode(root->right,minData);
            
                return root;
            }
        } 
        return root;
    }
};