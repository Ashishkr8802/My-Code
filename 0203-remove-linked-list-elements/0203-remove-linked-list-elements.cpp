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
    ListNode* removeElements(ListNode* head, int val) {

        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                // ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;  // Remove node
                // delete nodeToDelete;  // Free memory
            } else {
                temp = temp->next;  // Move forward only if no deletion
            }
        }
        return head;
    }
};