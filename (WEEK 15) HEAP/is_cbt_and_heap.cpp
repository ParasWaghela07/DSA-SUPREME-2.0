class Solution {
  public:
    bool isHeap(struct Node* tree) {
        queue<Node*>q;
        q.push(tree);
        bool checker=false;
        
        while(!q.empty()){
            auto front=q.front();q.pop();
            
            if(front==NULL){
                checker=true;
                continue;
            }
            
            if(checker) return false;
            
            if(front->left && front->data < front->left->data) return false;
            if(front->right && front->data < front->right->data) return false;
            
            q.push(front->left);
            q.push(front->right);
        }
        
        return true;
    }
};