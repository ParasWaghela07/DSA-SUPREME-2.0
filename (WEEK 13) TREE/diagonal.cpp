
//MAP METHOD// EXTRA SPACE

void solve(Node* root, map<int, vector<int>>& m, int d) {
    if (root == NULL) {
        return;
    }
    m[d].push_back(root->data);
    solve(root->left, m, d + 1);
    solve(root->right, m, d);
    
}

vector<int> diagonal(Node* root) {
    vector<int> ans;
    map<int, vector<int>> m;
    int d = 0;
    solve(root, m, d);

    for (auto &it : m) {
        vector<int> values = it.second;
        for (int val : values) {
            ans.push_back(val);
        }
    }

    return ans;
}

// BETTER METHOD // NO MAP

vector<int> diagonal(Node *root)
{
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       
       while(temp!=NULL){
           ans.push_back(temp->data);
           if(temp->left) q.push(temp->left);
           temp=temp->right;
       }
   }
   
   return ans;
}