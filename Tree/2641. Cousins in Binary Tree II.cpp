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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int levelsum = root->val;
        while(!q.empty()){
            int sz = q.size();
            int nextlevelsum = 0;
            while(sz--){
                auto node = q.front();
                q.pop();

                node->val = levelsum - node->val; 

                int siblingsum= (node->left ? node->left->val : 0);
                siblingsum+=(node->right ? node->right->val : 0);


                if(node->left){
                    nextlevelsum+=node->left->val;
                    node->left->val = siblingsum;
                    q.push(node->left);
                }

                if(node->right){
                    nextlevelsum+=node->right->val;
                    node->right->val = siblingsum;
                    q.push(node->right);
                }
            }
            levelsum = nextlevelsum;
        }
        return root;
    }
};
