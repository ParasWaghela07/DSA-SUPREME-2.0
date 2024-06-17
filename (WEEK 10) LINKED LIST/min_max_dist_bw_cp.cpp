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

---------- MINE ----------
class Solution {
public:
    bool isCritical(int &left,int &mid,int &right){
        if(left < mid && right < mid) return true;
        if(left > mid && right > mid) return true;

        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(!head || !head->next || !head->next->next ||!head->next->next->next) return {-1,-1};

        int index=1;

        ListNode*prev=head;
        ListNode*curr=head->next;
        ListNode*nxt=curr->next;

        int firstIndex=-1;
        int lastIndex=-1;


        int mini=INT_MAX;
        int maxi=INT_MIN;


        while(nxt){
            if(isCritical(prev->val,curr->val,nxt->val)){

                if(lastIndex!=-1){
                    mini=min(mini,index-lastIndex);
                    maxi=max(maxi,index-firstIndex);
                }

                if(firstIndex==-1){
                    firstIndex=index;
                }

                lastIndex=index;

            }
            nxt=nxt->next;
            curr=curr->next;
            prev=prev->next;
            index++;
        }

        if(mini==INT_MAX) return {-1,-1};

        return {mini,maxi};

    }
};



class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        ListNode* prev=head;
        if(prev==0){
            return ans;
        }
        ListNode* curr=head->next;
        if(curr==0){
            return ans;
        }
        ListNode* nxt=head->next->next;
        if(nxt==0){
            return ans;
        }

        int firstCP=-1;
        int lastCP=-1;
        int minDis=INT_MAX;
        int i=1;

        while(nxt){
            bool CP=((curr->val < prev->val && curr->val < nxt->val ) 
            || (curr->val > prev->val && curr->val > nxt->val )) ? true : false ;

            if(CP && firstCP ==-1){
                firstCP=i;
                lastCP=i;
            }
            else if(CP){
                minDis=min(minDis,i-lastCP);
                lastCP=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            nxt=nxt->next;
        }

        if(firstCP==lastCP){
            return ans;
        }
        else{
            ans[0]=minDis;
            ans[1]=lastCP-firstCP;
        }

        return ans;
    }
};