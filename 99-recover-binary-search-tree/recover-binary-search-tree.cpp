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
void inorder(TreeNode* root,vector<int>&v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
void update(TreeNode* root,vector<int>temp){
    if(!root) return;
    if(root->val == temp[0]) root->val = temp[1];
    else if(root->val == temp[1]) root->val = temp[0];
    update(root->left,temp);
    update(root->right,temp);
}
    void recoverTree(TreeNode* root) {
        vector<int>v1;
        inorder(root,v1);
        vector<int>v2(v1);
        sort(v2.begin(),v2.end());
        vector<int>temp;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
                temp.push_back(v1[i]);
        }
        update(root,temp);
    }
};