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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int size = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        int div = size / k;
        temp = head;

        ListNode* end = head;
        ListNode* prev = NULL;
        ListNode* before = NULL;

        while (div--) {

            int m = k;
            ListNode* curr = temp;
            prev = NULL;

    
            while (m--) {
                ListNode* dum = curr->next;

                curr->next = prev;
                prev = curr;
                curr = dum;
            }

    

            if (before == NULL) {
                head = prev;
            } else {
                before->next = prev;
            }

            temp->next = curr;
            before = temp;

        
            temp = curr;
        }

        return head;
    }
};