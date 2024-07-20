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
    void traverse(TreeNode*root,map<int,multiset<pair<int,int>>>&mp,int col,int row){
        if(!root) return;

        mp[col].insert({row,root->val});

        traverse(root->left,mp,col-1,row+1);
        traverse(root->right,mp,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>>mp;

        traverse(root,mp,0,0);

        vector<vector<int>>ans;

        for(auto it:mp){
            vector<int>temp;
            for(auto s:it.second){
                temp.push_back(s.second);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push( { root , {0,0} } );
        map<int,map<int,multiset<int>>>mp;


        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode*& node=front.first;
            auto coordinates=front.second;

            int&row=coordinates.first;
            int&col=coordinates.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }

            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto it:mp){
            auto& colmap=it.second;
            vector<int>v;

            for(auto it2:colmap){
                auto&mset=it2.second;
                v.insert(v.end(),mset.begin(),mset.end());
            }

            ans.push_back(v);
        }

        return ans;
    }
};