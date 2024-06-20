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
    void SanitizeMap(unordered_map<int,ListNode*>&mp,int sum,ListNode* stNode){
        int temp=sum;
        while(1){
            temp+=stNode->val;
            if(temp==sum) return;
            mp.erase(temp);
            stNode=stNode->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (!head->next &&  head->val==0)) return 0;
        unordered_map<int,ListNode*>mp;

        int sum=0;

        ListNode* it=head;

        while(it){
            sum+=it->val;

            if(sum==0){
                head=it->next;
                mp.clear();
            }
            else if(mp.find(sum)!=mp.end()){
                SanitizeMap(mp,sum,mp[sum]->next);
                mp[sum]->next=it->next;
            } 
            else{
                mp[sum]=it;
            }
            it=it->next;
        }

        return head;
    }
};