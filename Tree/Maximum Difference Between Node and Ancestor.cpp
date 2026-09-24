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
int maxdiff(TreeNode* root, int maxi, int mini){

    if(root == NULL){

        return abs(maxi-mini); // at the end return the maximum abs diff
    }

    mini = min(mini,root->val); // finding minimum val
    maxi = max(maxi,root->val); // finding maximum val

    int left = maxdiff(root->left,maxi,mini); 
    int right = maxdiff(root->right,maxi,mini);

    return max(left,right);  // returning max from left and right
}
    int maxAncestorDiff(TreeNode* root) {
        
        return maxdiff(root,root->val,root->val);
    }
};
