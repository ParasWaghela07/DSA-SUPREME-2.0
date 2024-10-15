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
    vector<TreeNode*>byRec(int s,int e){
        if(s>e) return {0};
        if(s==e) return {new TreeNode(s)};

        vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=byRec(s,i-1);
            vector<TreeNode*>right=byRec(i+1,e);

            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

     vector<TreeNode*>byMem(int s,int e, map<pair<int,int>,vector<TreeNode*>>&dp){
        if(s>e) return {0};
        if(s==e) return {new TreeNode(s)};

        if(dp.find({s,e})!=dp.end()){
            return dp[{s,e}];
        }

        vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=byMem(s,i-1,dp);
            vector<TreeNode*>right=byMem(i+1,e,dp);

            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];

                    ans.push_back(root);
                }
            }
        }

        return dp[{s,e}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        // return byRec(1,n);

        map<pair<int,int>,vector<TreeNode*>>dp;
        return byMem(1,n,dp);
    }
};