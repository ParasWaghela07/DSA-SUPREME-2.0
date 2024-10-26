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
----LEETCODE 2458 ----
    unordered_map<int,pair<int,int>>mp;
    unordered_map<int,pair<int,int>>lvl;

    int height(TreeNode*root,int level){
        if(!root) return 0;

        int lh=height(root->left,level+1);
        int rh=height(root->right,level+1);

        int currh=max(lh,rh)+1;

        if(lvl.find(level)!=lvl.end()){
            int h1=lvl[level].first;
            int h2=lvl[level].second;

            if(currh>h1){
                h2=h1;
                h1=currh;
            }
            else if(currh>h2){
                h2=currh;
            }

            lvl[level]={h1,h2};
        }
        else{
            lvl[level]={currh,-1};
        }
        mp[root->val]={currh,level};
        return currh;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int ttl=height(root,0);
        vector<int>ans;

        for(auto it:queries){
            auto curr=mp[it];

            int nodeheight=curr.first;
            int nodelevel=curr.second;

            cout<<"Node height : "<<nodeheight<<endl;
            cout<<"Node level : "<<nodelevel<<endl;


            int nodelevelmax=lvl[nodelevel].first;
            int nodelevelmax2=lvl[nodelevel].second;

            cout<<"nodelevelmax height : "<<nodelevelmax<<endl;
            cout<<"nodelevelmax2 height : "<<nodelevelmax2<<endl;

            if(nodeheight==nodelevelmax){
                if(nodelevelmax2==-1){
                    ans.push_back(ttl-nodeheight-1);
                }
                else{
                    ans.push_back(nodelevelmax2+nodelevel-1);
                }
            }
            else{
                ans.push_back(ttl-1);
            }
        }

        return ans;
    }
};