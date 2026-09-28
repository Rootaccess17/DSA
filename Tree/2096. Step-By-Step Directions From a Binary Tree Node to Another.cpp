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
void dfs(TreeNode* root,string &str,int value,string &ans){
    if(root==NULL) return ;

    if(root->val == value){
        ans = str;
        return ;
    }

    // for left
    str.push_back('L');
    dfs(root->left,str,value,ans);
    str.pop_back();

    // for right
    str.push_back('R');
    dfs(root->right,str,value,ans);
    str.pop_back();
}
TreeNode* LCA(TreeNode* root,int p , int q){
    if(root==NULL || root->val==p || root->val == q){
        return root;
    }

    TreeNode *left = LCA(root->left,p,q);
    TreeNode* right = LCA(root->right,p,q);

    if(left && right){
        return root;
    }

    return left ? left: right;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //step 1- find the LCA then the path 
        // step-2 startPath - LCA to startValue and then make its all char 'U'
        //step-3 destPath - LCA to destValue it remains as we store in str becuase it is correct as we want 


        TreeNode * lca = LCA(root,startValue,destValue);

        string startPath, destPath;
        string str="";
        dfs(lca,str,startValue,startPath);
        for(int i=0; i<startPath.size(); i++){
            startPath[i]='U';
        }
        str="";
        dfs(lca,str,destValue,destPath);

        return startPath+=destPath;
    }
};
