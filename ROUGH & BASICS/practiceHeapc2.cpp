#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void InsertinBst(Node *&root, int data)
{
    // 1st element che !
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    else
    {
        if (data > root->data)
        {
            InsertinBst(root->right, data);
        }
        else
        {
            InsertinBst(root->left, data);
        }
    }
}

void createBst(Node *&root)
{
    cout << "Enter Data : " << endl;
    int x;
    cin >> x;

    while (x != -1)
    {
        InsertinBst(root, x);
        cin >> x;
    }
}

void BFStraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void storeInorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    storeInorder(root->left, in);
    in.push_back(root->data);
    storeInorder(root->right, in);
}
void makeMinHeap(Node* root,vector<int>in,int &i){
    if(root==NULL){
        return;
    }

    //PRE ORDER-->NLR           // OR CAN BE DONE USING POST-ORDER BUT FOR THAT INORDER SHOULD BE RNL TO STORE DATA IN DESCENDING ORDER  
    root->data=in[i++];
    makeMaxHeap(root->left,in,i);
    makeMaxHeap(root->right,in,i);
    
}

void makeMaxHeap(Node* root,vector<int>in,int &i){
    if(root==NULL){
        return;
    }

    //POST ORDER-->LRN
    makeMaxHeap(root->left,in,i);
    makeMaxHeap(root->right,in,i);
    root->data=in[i++];
}

void convertBstToHeap(Node* root){
    vector<int>in;
    storeInorder(root,in);
    int index=0;
    makeMaxHeap(root,in,index);
}

int main()
{
    Node *root = NULL;
    createBst(root);

    cout << endl
         << "Old BST : " << endl;
    BFStraversal(root);

    convertBstToHeap(root);

    cout << endl
         << "New Max Heap : " << endl;
    BFStraversal(root);
}
