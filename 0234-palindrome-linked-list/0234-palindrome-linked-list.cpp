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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode*slow=head;
        ListNode*fast=head;
        int count=0;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        fast=fast->next;
        count++;

    }
    ListNode*curr=slow;
    ListNode*prev=NULL;
   
    while(curr!=NULL){
        ListNode*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
   ListNode* p1 = head;
   ListNode* p2 = prev;

   while(p2!=NULL){
    if(p1->val!=p2->val){
        return false;
    }
    p1=p1->next;
    p2=p2->next;
   }

return true;

    }
};