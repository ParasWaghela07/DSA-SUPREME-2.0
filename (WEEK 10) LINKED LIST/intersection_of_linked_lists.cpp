/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//MY SOLUTION 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        map<ListNode*,bool>table;

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=NULL || temp2!=NULL){

            if(temp1!=NULL){

                if(table[temp1]==false){
                table[temp1]=true;
                 }
            else{
                return temp1;
            }

            temp1=temp1->next;

            }

            if(temp2!=NULL){
                if(table[temp2]==false){
                table[temp2]=true;
            }
            else{
                return temp2;
            }
                temp2=temp2->next;
            }

    

        }

        return NULL;
    }
};

//////////////// O(M+N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1 && temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }

        if(temp1==NULL){
            temp1=headB;
            while(temp2){
                temp2=temp2->next;
                temp1=temp1->next;
            }

            temp2=headA;
        }
        else if(temp2==NULL){
            temp2=headA;
            while(temp1){
                temp1=temp1->next;
                temp2=temp2->next;
            }

            temp1=headB;
        }

        while(temp1 && temp2){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return NULL;
    }
};


//LAKSHAY BHAIYA SOLUTION

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1->next && temp2->next){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        int temp1len=0;
        int temp2len=0;

        while(temp1->next!=NULL){
            temp1=temp1->next;
            temp1len++;
        }

        while(temp2->next!=NULL){
            temp2=temp2->next;
            temp2len++;
        }

        while(temp1len){
            headA=headA->next;
            temp1len--;
        }

        while(temp2len){
            headB=headB->next;
            temp2len--;
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;


    }
};