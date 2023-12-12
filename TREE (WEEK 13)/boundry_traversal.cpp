#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;


	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}

void levelOrderTraversal(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  cout << endl;
  while(!q.empty()) {
	Node* temp = q.front();
	q.pop();

	if(temp == NULL) {
	  cout << endl;
	  if(!q.empty()) {
		q.push(NULL);
	  }
	}
	else {
	  cout << temp->data << " ";
	  if(temp->left != NULL) {
		q.push(temp->left);
	  }
	  if(temp->right != NULL) {
		q.push(temp->right);
	  }
	}


  }
}

void printLeftBoundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }

    cout<<root->data<<" ";
    if(root->left!=NULL)
    printLeftBoundary(root->left);
    else
    printLeftBoundary(root->right);
}

void printLeafNodes(Node* root){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);

}

void printRightBoundary(Node* root){
    if(root==NULL){
        return;
    }

    if(root->left!=NULL)
    printLeftBoundary(root->left);
    else
    printLeftBoundary(root->right);

    if(root->left==NULL && root->right==NULL){
        return;
    }

    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    printLeftBoundary(root->left);
    printLeafNodes(root->left);
    printLeafNodes(root->right);
    printRightBoundary(root->right);

}

int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
  levelOrderTraversal(root);

  boundaryTraversal(root);
  return 0;
}