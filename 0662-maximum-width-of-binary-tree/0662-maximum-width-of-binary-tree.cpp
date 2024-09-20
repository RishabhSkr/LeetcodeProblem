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

    int widthOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        queue<pair<TreeNode*,int> >q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int miniIdx = q.front().second; // normalize ke liye minIdx store kr rhe h overflow se bachna h
            int firstIdx,lastIdx;

            for(int i =0;i<size;++i){
                TreeNode * node = q.front().first;
                long currIdx = q.front().second - miniIdx; // normalize to 0 ,1,2,3...
                q.pop();

                if(i==0){
                    firstIdx = currIdx;
                }
                if(i==size-1){
                    lastIdx = currIdx;
                }
                if(node->left!=NULL)q.push({node->left,2*currIdx+1});
                if(node->right!=NULL)q.push({node->right,2*currIdx+2});
            }
            maxi =max(lastIdx-firstIdx+1,maxi);
        }
        return maxi;
    }
};