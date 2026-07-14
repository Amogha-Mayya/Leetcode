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
TreeNode* solve(int& idx,vector<int>& inorder, vector<int>& preorder,
int start, int end){
    if(start > end) return nullptr;
    int root_val = preorder[idx];
    idx++;
    int i=start;
    for(;i<=end;i++){
        if(inorder[i] == root_val)
            break;
    }
    TreeNode* newnode = new TreeNode(root_val);
    newnode->left = solve(idx,inorder,preorder,start,i-1);
    newnode->right = solve(idx,inorder,preorder,i+1,end);
    return newnode;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return solve(idx,inorder,preorder,0,n-1);
    }
};