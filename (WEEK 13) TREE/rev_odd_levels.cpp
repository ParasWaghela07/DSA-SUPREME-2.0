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
    void dfs(TreeNode*l,TreeNode*r,int level){
        if(!l || !r) return;

        if(level&1){
            swap(l->val,r->val);
        }

        dfs(l->left,r->right,level+1);
        dfs(l->right,r->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};


class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>nodes;
            while(n--){
                auto front=q.front();
                q.pop();

                nodes.push_back(front);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            if(level&1){
                int i=0;
                int j=nodes.size()-1;
                while(i<j){
                    swap(nodes[i]->val,nodes[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};


class Solution {
public:
    void bfs(TreeNode*root,unordered_map<int,vector<int>>&mp){
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto front=q.front();
                q.pop();

                mp[level].push_back(front->val);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            level++;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int,vector<int>>mp;
        bfs(root,mp);

        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto front=q.front();
                q.pop();

                if(level&1){
                    front->val=mp[level].back();
                    mp[level].pop_back();
                }
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            level++;
        }

        return root;
    }
};