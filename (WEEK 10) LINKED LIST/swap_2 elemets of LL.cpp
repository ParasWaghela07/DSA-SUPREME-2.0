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

------------SWAPPING VALUES------------- (EASY NOT EXPECTED IN INTERVIEW)
class Solution {
public:
    void swapValues(ListNode* head,ListNode* &temp,int &start,int k){
        if(!head){
            start=1;
            return;
        }

        if(start==k){
            temp=head;
        }
        start++;
        swapValues(head->next,temp,start,k);

        if(start==k){
            swap(temp->val,head->val);
        }

        start++;


    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=NULL;
        int start=1;
        swapValues(head,temp,start,k);
        return head;
    }
}; 
 
 --------------SO MANY EDGE CASES------------- ALL EDGE CASES ARE MENTIONED IN CODE

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
    int getlen(ListNode* head){
        ListNode* temp=head;
        int count=0;

        while(temp){
            temp=temp->next;
            count++;
        }

        return count;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=getlen(head);

        int left=k;
        int right=len-k+1;

        //case 1 on same node
        if(left==right) return head;

        //case 2
        if(len==2){
            ListNode*temp=head->next;
            temp->next=head;
            head->next=NULL;
            head=temp;

            return head;
        }

        //case 3 to follow general swapping method in case left and right crosses each other
        //left always in left , right always in right
        if(left>right){
            swap(left,right);
        }

        //case 4 :- 1st and last node

        if(left==1){

            ListNode* curr=head;
            ListNode* prev=NULL;
            while(curr->next){
            prev=curr;
            curr=curr->next;
            }

            curr->next=head->next;
            prev->next=head;
            head->next=NULL;
            head=curr;

            return head;
        }

        //case 5:-just adjacent nodes swapping
        if(left==right-1){
            ListNode* p1=NULL;
            ListNode* n1=head;

            while(left!=1){
                p1=n1;
                n1=n1->next;
                left--;
                }

                ListNode* p2=NULL;
                ListNode* n2=head;

                while(right!=1){
                    p2=n2;
                    n2=n2->next;
                    right--;
                }

                ListNode* temp=n2->next;
                n2->next=n1;
                n1->next=temp;
                p1->next=n2;

                return head;
        }

        //case 6:- nodes are at somewhere middle with dist >1
        
            ListNode* p1=NULL;
            ListNode* n1=head;

            while(left!=1){
                p1=n1;
                n1=n1->next;
                left--;
                }

                ListNode* p2=NULL;
                ListNode* n2=head;

                while(right!=1){
                    p2=n2;
                    n2=n2->next;
                    right--;
                }

                ListNode* temp=n1->next;
                n1->next=n2->next;
                n2->next=temp;
                p1->next=n2;
                p2->next=n1;

        return head;
    }
};



