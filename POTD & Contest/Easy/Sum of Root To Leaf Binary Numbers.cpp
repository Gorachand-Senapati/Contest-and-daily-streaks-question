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
    int dfs(TreeNode* root, int curr){
        if(!root) return 0;//if no root
         curr = curr* 2+ root->val;//here calculate bin to decimal
        if(!root->left && !root->right){//if finish
            return curr;
        }
        return dfs(root->left,curr) + dfs(root->right,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};