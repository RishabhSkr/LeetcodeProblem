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
    int cntSwaps(vector<int>&arr){
         vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[copy[i]] = i; 
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (mp[arr[i]] != i) {
                swap(arr[i], arr[mp[arr[i]]]);
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int cnt =0;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;++i){
                auto node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            cnt+=cntSwaps(temp);
        }
        return cnt;
    }
};