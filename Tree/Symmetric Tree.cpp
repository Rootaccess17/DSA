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
bool check(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL) return true; // if both null

    if(p==NULL || q==NULL) return false; // if one is null

    if(p->val != q->val) return false;  // if both not null but not equal

    return check(p->left,q->right) && check(p->right,q->left);
}
    bool isSymmetric(TreeNode* root) {
        
        return check(root->left,root->right);
    }
};
