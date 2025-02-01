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
        --importance of dummy node at start (b1)--ONE PASS--
class Solution {
public:
    ListNode* rev(ListNode*head,int left,int right){
        ListNode*b1=new ListNode(-1);
        b1->next=head;
        ListNode*temp=head;

        int a=left;
        int b=right;

        while(a>1){
            b1=temp;
            temp=temp->next;
            a--;
        }

        int c=right-left;

        ListNode*prev=temp;
        ListNode*curr=temp->next;
        while(c--){
            ListNode*tp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tp;
        }

        b1->next->next=curr;
        b1->next=prev;

        if(left>1) return head;
        else return b1->next;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode*ans=rev(head,left,right);
        return ans;
    }
};

--MULTIPLE PASSES--
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
    ListNode*rev(ListNode*head){
        ListNode*prev=NULL;
        ListNode*curr=head;

        while(curr){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        int a=left;
        while(a>1){
            prev=curr;
            curr=curr->next;
            a--;
        }
        ListNode*rightEnd=curr;
        int len=right-left;
        while(len--){
            rightEnd=rightEnd->next;
        }
        ListNode*tp=rightEnd->next;
        rightEnd->next=NULL;
        rightEnd=tp;

        ListNode*newLeftHead=rev(curr);
        if(prev) prev->next=newLeftHead;

        curr->next=rightEnd;
        if(left==1) return newLeftHead;
        else return head;
    }
};