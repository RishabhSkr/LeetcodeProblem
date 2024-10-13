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
    priority_queue<int, vector<int>, greater<int>> pq;
    int solve(TreeNode * root,int k){
        if(root==NULL)return 0;

        int leftSubTree= solve(root->left,k);
        int rightSubTree = solve(root->right,k);

        if((root->left!=NULL && root->right==NULL) || (root->left==NULL && root->right!=NULL ))return -1;

        if(leftSubTree==-1 || rightSubTree==-1 || leftSubTree!=rightSubTree)return -1;

        if(pq.size()<k)pq.push(leftSubTree+rightSubTree+1);
        else{
            if(pq.top()<leftSubTree+rightSubTree+1){
                pq.pop();
                pq.push(leftSubTree+rightSubTree+1);
            }
        }
        return leftSubTree+rightSubTree+1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        solve(root,k);
        if(pq.size()<k)return -1;

        return pq.top();
    }
};