/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void buildgraph(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*, vector<TreeNode*>>&adj){
    if(root == NULL) return ;

    if(parent!=NULL){
        adj[root].push_back(parent);
        adj[parent].push_back(root);
    }
    buildgraph(root->left,root,adj);
    buildgraph(root->right,root,adj);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, vector<TreeNode*>> adj; // make undirected graph beacause tree can not access the parent or not go above it only goes to left and right
        buildgraph(root,NULL,adj);
        vector<int>ans;
        unordered_set<TreeNode*>vis;
        vis.insert(target);
        queue<TreeNode*>q;
        q.push(target);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            while(sz--){
                auto node = q.front();
                q.pop();
                if(level == k){
                    ans.push_back(node->val);
                    flag= true;
                }
                for(auto it: adj[node]){
                    if(!vis.count(it)){
                        q.push(it);
                        vis.insert(it);
                    }
                }
            }
            level++;
            if(flag) break;
        }

        return ans;
    }
};
