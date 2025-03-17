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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* ptr = head;
        ListNode* temp = NULL;

        // head = head->next;

        while(ptr != NULL && ptr->next != NULL) {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next = ptr;
            if(prev == NULL) {
                head = temp;
            }
            else {
                prev->next = temp;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};