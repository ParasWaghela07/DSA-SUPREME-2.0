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

//MY SOLUTION
//WITH TRAVERSING ARRAY

class Solution {
public:

vector<int> NextGreater(vector<int>&qst){
    stack<int>st;

    vector<int>ans(qst.size());

    for(int i=qst.size()-1;i>=0;i--){

        while(!st.empty() && qst[i]>=st.top()){
            st.pop();
        }

        if(!st.empty()){
            ans[i]=st.top();
        }
        else{
            ans[i]=0;
        }

        st.push(qst[i]);


    }

    return ans;
}
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>qst;

        ListNode* temp=head;
        while(temp!=NULL){
            qst.push_back(temp->val);
            temp=temp->next;
        }

        return NextGreater(qst);
    }
};

//WITH TRAVERSING LL

void rev(ListNode* &head){
    ListNode* prev=NULL;
    ListNode* curr=head;

    while(curr!=NULL){
        ListNode* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }

    head=prev;
}
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<int>st;

        rev(head);

        ListNode* temp=head;

        while(temp!=NULL){

            while(!st.empty() && temp->val>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top());
            }
            else{
                ans.push_back(0);
            }

            st.push(temp->val);
            temp=temp->next;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

//LAKSHAY BHAIYA'S SOLUTION

vector<int> nextLargerNodes(ListNode* head) {
    vector<int>ll;
    while(head){
        ll.push_back(head->val);
        head=head->next;
    }

    stack<int>st;
    vector<int>ans(ll.size());

    for(int i=0;i<ll.size();i++){
        while(!st.empty() && ll[i]>ll[st.top()]){
            int kid=st.top();
            st.pop();
            ans[kid]=ll[i];
        }
        st.push(i);
    }
    return ans;
}

