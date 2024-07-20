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

 LEETCODE 2196
class Solution {
public:
    TreeNode* makeTree(int rootValue,unordered_map<int,vector<pair<int,int>>>&mp){

        TreeNode* root=new TreeNode(rootValue);

        if(mp.find(rootValue)!=mp.end()){
        vector<pair<int,int>>childs=mp[rootValue];

        for(auto p:childs){
            if(p.second==1) root->left=makeTree(p.first,mp);
            else root->right=makeTree(p.first,mp);
        }

        }

        return root;

    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>>mp;
        unordered_set<int>childs;

        for(auto v:descriptions){
            int parent=v[0];
            int child=v[1];
            int isLeft=v[2];

            mp[parent].push_back({child,isLeft});
            childs.insert(child);
        }
        int root;
        for(auto it:mp){
            if(childs.find(it.first)==childs.end()){
                root=it.first;
                break;
            }

        }
        TreeNode* finalroot=makeTree(root,mp);

        return finalroot;
    }
};