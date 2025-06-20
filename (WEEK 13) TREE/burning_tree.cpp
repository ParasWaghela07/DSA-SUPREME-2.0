class Solution {
  public:
    void solve(Node*root,unordered_map<int,vector<int>>&adj){
        if(!root) return;
        
        if(root->left){
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
        }
        if(root->right){
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
        }
        
        solve(root->left,adj);
        solve(root->right,adj);
    }
    
    int minTime(Node* root, int target) {
        unordered_map<int,vector<int>>adj;
        solve(root,adj);
        
        queue<int>q;
        unordered_set<int>st;
        
        q.push(target);
        int cnt=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int front=q.front();
                q.pop();
                
                st.insert(front);
                for(auto &it:adj[front]){
                    if(!st.count(it)){
                        q.push(it);
                    }
                }
            }
            
            cnt++;
        }
        
        return cnt-1;
    }
};


class Solution {
  public:
  
  
    Node* MakeNodeToParentMappingAndFindTarget(Node* root, unordered_map<Node*,Node*>&parentMap, int target){
        Node* targetNode=0;
        queue<Node*>q;
        q.push(root);
        parentMap[root]=0;
        
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
              targetNode=front;  
            }
            
            if(front->left){
                q.push(front->left);
                parentMap[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                parentMap[front->right]=front;
            }
        }
        return targetNode;
    }
    
    int BurnTheTree(Node* target,unordered_map<Node*,Node*>&parentMap){
        unordered_map<Node*,bool>isBurnt;
        queue<Node*>q;
        int t=0;
        
        q.push(target);
        isBurnt[target]=true;
        
        while(!q.empty()){
            int size=q.size();
            bool isFireSpreaded=false;
            
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                
                if(front->left && !isBurnt[front->left]){
                    q.push(front->left);
                    isBurnt[front->left]=true;
                    isFireSpreaded=true;
                }
                if(front->right && !isBurnt[front->right]){
                    q.push(front->right);
                    isBurnt[front->right]=true;
                    isFireSpreaded=true;
                }
                if(parentMap[front] && !isBurnt[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]]=true;
                    isFireSpreaded=true;
                }
            }
            if(isFireSpreaded==true) t++; 
        }
        return t;
        
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parentMap;//Node to parent mapping
        Node* targetNode=MakeNodeToParentMappingAndFindTarget(root,parentMap,target);
        
        return BurnTheTree(targetNode,parentMap);
        
        
        
    }
};