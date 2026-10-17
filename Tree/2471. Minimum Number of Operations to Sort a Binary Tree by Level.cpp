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
int minop(vector<int>&vec,unordered_map<int,int>&mp){
    int steps=0;
    vector<int>sorted(vec.begin(),vec.end());
    sort(sorted.begin(),sorted.end());

    for(int i=0; i<vec.size(); i++){
        if(vec[i] == sorted[i]) continue;

        int ind = mp[sorted[i]];
        mp[vec[i]] = ind;
        swap(vec[ind],vec[i]);
        steps++;
    }
    return steps;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        int steps=0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>vec;
            unordered_map<int,int>mp;
            int i=0;
            while(sz--){
                auto node= q.front();
                q.pop();
                vec.push_back(node->val);
                mp[node->val] = i;
                i++;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            steps+= minop(vec,mp);
        }
        return steps;
    }
};
