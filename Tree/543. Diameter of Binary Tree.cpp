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
int maxdia = 0;
int solve(TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int left = solve(root->left);
    int right = solve(root->right);
    maxdia = max(maxdia,left+right);
    return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        
        solve(root);
        return maxdia;
    }
};
