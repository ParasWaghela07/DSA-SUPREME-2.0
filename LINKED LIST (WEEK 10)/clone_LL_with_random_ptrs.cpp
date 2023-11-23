//not good approach due to space complexity

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

Node* helper(Node* head, unordered_map<Node*,Node*> &map){
    if(head==NULL){
        return 0;
    }

    Node* newnode=new Node*(head->val);
    map[head]=newnode;

    newnode->next=helper(head->next,map);

    if(head->random){
        newnode->random=map[head->random];
    }

    return newnode;
}
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>map;

        return helper(head,map);
    }
};



//BETTER APPROACH

  Node* copyRandomList(Node* head) {

        if(!head){
            return 0;
        }

        //STEP 1 : CLONE LL AND MERGE IT TO OG LL

        Node* it=head;

        while(it){
            Node* clonednode=new Node(it->val);
            clonednode->next=it->next;
            it->next=clonednode;
            it=it->next->next;
        }

        //STEP 2 : ASSIGN RANDOM POINTERS TO CLONED LL

        it=head;

        while(it){
            Node* clonednode=it->next;
            clonednode->random=it->random?it->random->next:NULL;
            it=it->next->next;
        }

        //STEP 3 : DETTACH MERGED LL

        it=head;
        Node* clonedHead=it->next;

        while(it){
            Node* clonednode=it->next;
            it->next=it->next->next;
            
            if(clonednode->next)
            clonednode->next=clonednode->next->next;

            it=it->next;
        }

        return clonedHead;
    }
};