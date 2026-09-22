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
int find(int ele,vector<int>& inorder){

    for(int i=0; i<inorder.size(); i++){

        if(inorder[i] == ele) return i;
    }

    return -1;
}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &pre,int st, int end){
    int m = preorder.size();
    if(st > end || pre >= m) return NULL;
    
    int ele = preorder[pre++];
    TreeNode* root = new TreeNode(ele);

    int ind = find(ele,inorder);

    root->left = solve(preorder,inorder,pre,st,ind-1);  // when we find the index of root in inorder then left of this index are in left child
    root->right = solve(preorder,inorder,pre,ind+1,end);   // when we find the index of root in inorder then right of this index are in right child

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();

        int pre = 0;

        TreeNode* root = solve(preorder,inorder,pre,0,m-1);

        return root;

    }
};
