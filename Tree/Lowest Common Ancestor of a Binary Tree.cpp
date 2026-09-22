/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {   // METHOD - 1
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;  // if both left and right are present then root will always be LCA

        return right ? right : left; // if either be present left or right
    }
};


// METHOD - 2;

class Solution {
public:
bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(root == nullptr)
            return false;

        path.push_back(root);

        if(root == target)
            return true;

        if(findPath(root->left, target, path) ||
           findPath(root->right, target, path))
            return true;

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        findPath(root, p, pathP);  // FIND THE ANCESTORS OF P 
        findPath(root, q, pathQ); //  FIND THE ANCESTORS OF Q

        TreeNode* ans = nullptr;

        int i = 0; // FIND THE FIRST COMMON ANCESTOR , AND OUR LCA AS WELL . 
        while(i < pathP.size() && i < pathQ.size()) {
            if(pathP[i] != pathQ[i])  
                break;

            ans = pathP[i];
            i++;
        }

        return ans;
    }
};
