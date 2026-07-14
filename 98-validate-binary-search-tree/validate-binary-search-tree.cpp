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
void inorder(TreeNode* root,vector<int>& v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        unordered_set<int>s;
        inorder(root,v);
        if(!is_sorted(v.begin(),v.end())) return false;
        for(auto i:v)
            s.insert(i);
        return (v.size() == s.size());
    }
};