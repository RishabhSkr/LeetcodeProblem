/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
     // we cannot move from tar which is not root to parent  in tree we need to make a map parent child.
     //2. after making push ithe tar to queue and check left right and parent if not vis mark push them and mark vis decrease k by 1;
class Solution {
public:
    unordered_map<int,TreeNode *>parent;
    unordered_set<TreeNode*>vis;
    void findParent(TreeNode * root){
        if(root==NULL)return ;
        if(root->left!=NULL){
            parent[root->left->val]=root;
        }
        if(root->right!=NULL){
            parent[root->right->val]=root;
        }
        findParent(root->left);
        findParent(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>ans;
        // mark parent
        findParent(root);
        // apply bfs over target with dist k traverse if k=0 break;
        queue<TreeNode*>q;
        q.push(target);
        
        while(!q.empty()){
            if(k==0){
                break;
            }
            int size = q.size();
            while(size>0){
                auto node = q.front();
                vis.insert(node);
                q.pop();
                // check left 
                if(node->left!=NULL && vis.count(node->left)==0){
                    q.push(node->left);
                }
                // check right
                if(node->right!=NULL && vis.count(node->right)==0){
                    q.push(node->right);
                }
                // check for parent 
                 if(parent.count(node->val)>0 && vis.count(parent[node->val])==0){
                    q.push(parent[node->val]);
                }
                size--;
            }
            k--;
        }
        // bahar aa gye k==0 jo que me wo ans
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};