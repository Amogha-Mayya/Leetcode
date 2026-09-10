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
int dfs(TreeNode* root){
    if(!root) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    return left + right + 1;
}
int sum(TreeNode* root){
    if(!root) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    return root->val + left + right;
}
int count = 0;
void solve(TreeNode* root){
    if(!root) return;
    int cnt = dfs(root);
    int summy = sum(root);
    if(summy/cnt == root->val) count++;
    solve(root->left);
    solve(root->right);
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};