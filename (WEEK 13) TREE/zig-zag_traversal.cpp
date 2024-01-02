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


//MY SOLUTION

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        bool flag=true;

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            if(front==NULL){
                if(flag==false){
                    reverse(temp.begin(),temp.end());
                }
                flag=(!flag);
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{

                temp.push_back(front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }

        }

        return  ans;
    }
};

//LAKSHAY BHAIYA'S SOLUTION //BETTER SOLUTION

 vector<vector<int>>ans;
    if(!root) return ans;

    bool flag=true;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int>temp(size);

        for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();

            int index= flag ? i : size-i-1;
            temp[index]=front->val;

                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
        }
        flag=(!flag);
        ans.push_back(temp);
    }
return ans;
    