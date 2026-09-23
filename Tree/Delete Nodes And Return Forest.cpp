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
TreeNode* dfs(vector<TreeNode*> &ans,TreeNode* root,unordered_map<int,bool>&mp){
    if(root == NULL) return NULL;

// we are using bootom up dfs so that we can delete node safely and also take care of all other nodes

    root->left = dfs(ans,root->left,mp); // just changes the links 
    root->right = dfs(ans,root->right,mp);

    if(mp[root->val]){
        if(root->left != NULL){
            ans.push_back(root->left);  // if node found in map and its left child is not null then store the full left subtree
        }

        if(root->right != NULL){
            ans.push_back(root->right); // if node found in map and its right child is not null then store the full right subtree
        }

        return NULL;
    }

    else{
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool>mp;

        for(auto it: to_delete){
            mp[it] = true;
        }

        vector<TreeNode*>ans;

        dfs(ans,root,mp);

        if(!mp[root->val]){  // if root is not deleted then check beacuse we have not stored it earlier
            ans.push_back(root);
        }

        return ans;
    }
};
