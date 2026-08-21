/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
int size=0;
ListNode*temp=head;

while(temp!=NULL){
    size++;
    temp=temp->next;
}
if(size==1){
    if(n==1)return NULL;
}
n=size-n-1;
temp=head;
if(n<0){
    ListNode*ne=temp->next;
    temp->next=NULL;
    head=ne;
    return head;
}


while(temp!=NULL && n--){
    temp=temp->next;
}
ListNode*curr=temp->next;
curr=curr->next;
temp->next=curr;

return head;

    }
};