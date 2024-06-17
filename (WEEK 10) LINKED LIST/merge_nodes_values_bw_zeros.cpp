/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* it=head->next;
        ListNode* newHead=NULL;
        int sum=0;

        while(it){
            if(it->val==0){
                ListNode* newNode=new ListNode(sum);

                if(prev){
                    prev->next=newNode;
                }

                if(!newHead){
                    newHead=newNode;
                }

                prev=newNode;
                sum=0;
                it=it->next;
            }
            else{
                sum += it->val;
                it=it->next;
            }
        }

        while(head){
            ListNode* temp=head->next;
            head->next=0;
            delete head;
            head=temp;
        }

        return newHead;
    }
};



//MY SOLUTION

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(head==0 || head->next==0){
            return head;
        }

        ListNode* adder=head->next;
        ListNode* curr=head->next->next;
        head->next=NULL;
        delete head;
        head=adder;

        while(curr!=NULL && curr->next!=NULL){
            
            if(curr->val !=0){
                adder->val=adder->val+curr->val;
                ListNode* nxt=curr->next;
                adder->next=curr->next;
                curr->next=NULL;
                delete curr;
                curr=nxt;
            }
            else{
                adder->next=curr->next;
                adder=curr->next;
                curr->next=NULL;
                delete curr;
                curr=adder->next;
            }
        }

        adder->next=NULL;
        delete curr;

        return head;


    }
};


//LAKSHAY BHAIYA'S SOLUTION

 if(!head) return 0;

        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* lastNode=0;
        
        int sum=0;

        while(fast){
            if(fast->val!=0)
            {
            sum=sum+fast->val;
            fast=fast->next;
            }

            else
            {
            slow->val=sum;
            lastNode=slow;
            slow=slow->next;
            fast=fast->next;
            sum=0;
            }
        }

        ListNode* temp=lastNode->next;
        lastNode->next=NULL;

        while(temp){
            ListNode* nxt=temp->next;
            temp->next=NULL;
            delete temp;
            temp=nxt;  
        }

        return head;