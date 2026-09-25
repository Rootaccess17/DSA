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
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,ll>>q;

        q.push({root,0});
        ll ans = 1;
        while(!q.empty()){
            ll sz = q.size();
            ll st= q.front().second;
            ll end = q.back().second;
            ans = max(ans,end-st+1);
            while(sz--){
                auto [node,level] = q.front();
                q.pop();

                if(node->left) q.push({node->left,2*level+1});
                if(node->right) q.push({node->right,2*level+2});
            }
        }

        return ans;
    }
};
