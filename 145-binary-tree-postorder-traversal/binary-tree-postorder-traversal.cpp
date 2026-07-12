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
void solve(TreeNode* root,vector<int>& v){
    if(!root) return;
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }
    while(!st2.empty()){
        v.push_back(st2.top()->val);
        st2.pop();
    }
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        return v;
    }
};