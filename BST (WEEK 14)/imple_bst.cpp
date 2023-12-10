#include <iostream>
#include<queue>
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

void InsertinBst(Node* &root,int data){
    //1st element che !
    if(root==NULL){
        root=new Node(data);
        return;
    }
    else{
        if(data > root->data){
            InsertinBst(root->right,data);
        }
        else{
            InsertinBst(root->left,data);
        }
    }
}


void createBst(Node* &root)
{
    cout << "Enter Data : ";
    int x;
    cin >> x;

    while (x != -1)
    {
        InsertinBst(root, x);
        cout << "Enter Data : ";
        cin >> x;
    }
}

void BFStraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void FindMinimum(Node* root){
    if(root==NULL){
        return;
    }
    else if(root->left ==NULL && root->right==NULL ){
        cout<<root->data<<endl;
    }
    else{
        FindMinimum(root->left);
    }
}

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}


void FindMaximum(Node* root){
    if(root==NULL){
        return;
    }
    else if(root->left ==NULL && root->right==NULL ){
        cout<<root->data<<endl;
    }
    else{
        FindMaximum(root->right);
    }
}

Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

bool isPresent(Node* root,int val){
    if(root==NULL){
        return false;
    }

    if(root->data == val ){
        return true;
    }

    bool leftans=isPresent(root->left,val);
    bool rightans=isPresent(root->right,val);

    return leftans||rightans;
}

Node* deleteNode(Node* root,int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data==target){
        //case 1
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return  child;
        }
        else if(root->right==NULL && root->left!=NULL){
            Node* child=root->left;
            delete root;
            return  child;
        }
        else{
            Node* leftMax=minValue(root->left);
            root->data=leftMax->data;

            root->left=deleteNode(root->left,leftMax->data);
            return root;

        }
    }
    else if(root->data>target){
        root->left=deleteNode(root->left,target);
    }
    else{
        root->right=deleteNode(root->right,target);
    }

    return root;
}

int main()
{
    Node* root = NULL;
    createBst(root);

    BFStraversal(root);

    // cout<<"Preorder : ";
    // preorder(root);
    // cout<<endl;
    // cout<<"Inorder : ";
    // inorder(root);
    // cout<<endl;
    // cout<<"Postorder : ";
    // postorder(root);
    // cout<<endl;

    // cout<<"Minimum element is : ";
    // FindMinimum(root);
    // cout<<"Maximum element is : ";
    // FindMaximum(root);

    // int x;
    // cout<<"Enter Target : ";
    // cin>>x;

    // if(isPresent(root,x)){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT FOUND"<<endl;
    // }

    int target ;
	cout << "Enter the value of target: " << endl;
	cin >> target;

	while(target != -1) {
		root = deleteNode(root,  target);
		cout << endl << "Printing Level Order Traversal: " << endl;
		BFStraversal(root);

		cout << "Enter the value of target: " << endl;
		cin >> target;
		
	}
}