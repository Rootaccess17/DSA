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
int cnt=0;
int solve(TreeNode* root){
    if(root == NULL) return 0;

    int left = solve(root->left);
    int right = solve(root->right);

    cnt += abs(left) + abs(right);  // here we are couting the total moves from left and right

    return root->val -1 + left + right;  // we are balancing the coins in its subtree also keep in mind the node as well
}
    int distributeCoins(TreeNode* root) {
        
        solve(root);
        return cnt;
    }
};
