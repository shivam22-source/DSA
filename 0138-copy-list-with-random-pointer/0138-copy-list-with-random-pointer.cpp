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
    Node* copyRandomList(Node* head) {
        Node*curr=head;
        Node*prev=NULL;
        Node*copy=NULL;
        unordered_map<Node*,Node*>mp;
        while(curr){
            Node* temp=new Node(curr->val);
            mp[curr]=temp;
            if(copy==NULL){
                copy=temp;
                prev=copy;
            }
            else {
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }//7->13->11->10->1 and mp[a]->x...

    curr=head;
    Node*ans=copy;
    while(curr){
        copy->random=mp[curr->random];
        curr=curr->next;
        copy=copy->next;
        
    }
    return ans;
    }
};