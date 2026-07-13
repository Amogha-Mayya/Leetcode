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
            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            m[col][row].insert(node->val);
            if(it.first->left) q.push({it.first->left,{row+1,col-1}});
            if(it.first->right) q.push({it.first->right,{row+1,col+1}});
        }
    }

    for(auto i:m){
        vector<int>temp;
        for(auto j:i.second){
            for(auto k:j.second)
                temp.push_back(k);
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