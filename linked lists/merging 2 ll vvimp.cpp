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
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Create dummy node to avoid uninitialized pointer
        ListNode dummy;  // used to make new ll
        ListNode* head3 = &dummy; 
        dummy.next = nullptr;

        ListNode* current = head3; // will be used for building the merged list

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val > temp2->val) {
                current->next = new ListNode(temp2->val);
                current = current->next;
                temp2 = temp2->next;
            }
            else if (temp1->val == temp2->val) {
                current->next = new ListNode(temp1->val);
                current = current->next;
                current->next = new ListNode(temp2->val);
                current = current->next;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else { // temp1->val < temp2->val
                current->next = new ListNode(temp1->val);
                current = current->next;
                temp1 = temp1->next;
            }
        }

        // Attach remaining nodes
        while (temp1 != nullptr) {
            current->next = new ListNode(temp1->val);
            current = current->next;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            current->next = new ListNode(temp2->val);
            current = current->next;
            temp2 = temp2->next;
        }

        return dummy.next; // return actual head
    }
};
