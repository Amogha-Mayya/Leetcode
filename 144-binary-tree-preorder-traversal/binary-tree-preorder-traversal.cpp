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
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        v.push_back(temp->val);
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        return v;
    }
};