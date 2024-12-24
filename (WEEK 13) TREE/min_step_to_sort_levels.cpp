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
    int selectionSort(vector<int>&nums){
        int op=0;
        for(int i=0;i<nums.size()-1;i++){
            int miniIndex=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[miniIndex]){
                    miniIndex=j;
                }
            }
            if(miniIndex!=i){
                swap(nums[i],nums[miniIndex]);
                op++;
            }
        }

        return op;
    }

    int cyclicSort(vector<int>&nums){
        int ans=0;

        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=i;

        for(int i=0;i<temp.size();i++){
            if(nums[i]!=temp[i]){
                int index=mp[temp[i]];

                mp[nums[i]]=index;
                mp[nums[index]]=i;
                swap(nums[index],nums[i]);

                ans++;
            }
        }

        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int count=0;

        while(!q.empty()){
            int n=q.size();
            vector<int>nums;
            while(n--){
                auto front=q.front();
                q.pop();

                nums.push_back(front->val);

                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }

            count+=cyclicSort(nums);
        }

        return count;
    }
};