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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l_1 = list1;
        ListNode* l_2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (l_1 != nullptr && l_2 != nullptr) {
            if (l_1->val <= l_2->val) {
                temp->next = l_1;
                l_1 = l_1->next;
            } else {
                temp->next = l_2;
                l_2 = l_2->next;
            }
            temp = temp->next;
        }
        while (l_1 != NULL) {
            temp->next = l_1;
            temp = temp->next;
            l_1 = l_1->next;
        }
       while (l_2 != NULL) {
            temp->next = l_2;
            temp = temp->next;
            l_2 = l_2->next;
        }
        return dummy->next;
    }
};