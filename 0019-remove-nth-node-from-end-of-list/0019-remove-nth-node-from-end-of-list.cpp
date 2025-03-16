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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }

        count = count - n;
        if(count == 0) {
            head = head->next;
            return head;
        }
        temp = head;
        while(count - 1 != 0) {
            temp = temp->next;
            count--;
        }

        temp->next = temp->next->next;
        

        return head;
    }
};