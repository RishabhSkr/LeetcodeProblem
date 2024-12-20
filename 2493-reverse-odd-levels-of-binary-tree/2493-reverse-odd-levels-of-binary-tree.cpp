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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool isOdd = false;
        while(!q.empty()){
            vector<TreeNode *>temp;
            int size=q.size();
            for(int i=0;i<size;++i){
                auto node = q.front();
                q.pop();    
                temp.push_back(node);

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
                if(isOdd){
                    for(int i =0;i<size/2;++i){
                        swap(temp[i]->val,temp[size-i-1]->val);
                    }
                }
                isOdd=!isOdd;
        }
        return root;
    }
};