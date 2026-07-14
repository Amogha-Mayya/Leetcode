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
void solve(TreeNode* root,vector<vector<int>>& v){
    if(!root) return;
    // col -> row -> data
    map<int,map<int,multiset<int>>>m;
    // node -> row -> col
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto it = q.front();
            TreeNode* curr = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            m[col][row].insert(curr->val);
            if(curr->left) q.push({curr->left,{row+1,col-1}});
            if(curr->right) q.push({curr->right,{row+1,col+1}});
        }
    }

    for(auto i:m){
        vector<int>temp;
        for(auto j:i.second){
            for(auto k:j.second){
                temp.push_back(k);
            }
        }
        v.push_back(temp);
    }
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        solve(root,v);
        return v;
    }
};