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
long long maxi= LLONG_MIN;
int solve(TreeNode* root){
    if(root == NULL) return LLONG_MIN;

    long long left = solve(root->left);  // return left subtree sum
    long long right = solve(root->right); // return right subtree sum

    long long sum = max({left+right+root->val,max(left,right)+1LL*(root->val),1LL*root->val}); // choose the best sum {left+right+root,left+root,right+root,root}

    maxi = max(maxi,sum); // store the best sum

    return  max({left+1LL*root->val,right+1LL*root->val,1LL*root->val,0LL}); // to make path return best either {left+root,right+root,root,0}
}
    int maxPathSum(TreeNode* root) {
        
        solve(root);

        return maxi;
    }
};
