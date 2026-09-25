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
long long maxi = LLONG_MIN;
int mod = 1e9+7;
long long solve(TreeNode* root,int totalsum){
    if(root == NULL) return 0;


    long long left = solve(root->left,totalsum);
    long long right = solve(root->right,totalsum);
    
    long long sum = left+right+root->val;
    long long remsum = totalsum - (sum);

    maxi = max(maxi, remsum*sum);

    return sum;

}
    int maxProduct(TreeNode* root) {
        int totalsum = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            totalsum+=node->val;
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        solve(root,totalsum);
        return maxi%mod;
    }
};
