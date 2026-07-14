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
TreeNode* solve(int& idx,vector<int>& inorder, vector<int>& postorder,
int start, int end){
    if(start > end) return nullptr;
    int root_val = postorder[idx];
    idx--;
    int i=start;
    for(;i<=end;i++){
        if(inorder[i] == root_val)
            break;
    }
    TreeNode* newnode = new TreeNode(root_val);
    newnode->right = solve(idx,inorder,postorder,i+1,end);
    newnode->left = solve(idx,inorder,postorder,start,i-1);
    return newnode;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return solve(idx,inorder,postorder,0,n-1);
    }
};