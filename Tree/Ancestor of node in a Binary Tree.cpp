bool solve(TreeNode* root, int x, vector<int>& path) {
    if(root == nullptr)
        return false;

    if(root->val == x)
        return true;

    path.push_back(root->val);

    if(solve(root->left, x, path) ||
       solve(root->right, x, path))
        return true;

    path.pop_back();   // backtrack
    return false;
}


vector<int> (TreeNode* root, int x){
  vector<int> path;
  solve(root, x, path);

  return path;
}
};
