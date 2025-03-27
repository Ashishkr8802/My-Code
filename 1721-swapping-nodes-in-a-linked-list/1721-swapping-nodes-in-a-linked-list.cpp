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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* end = head;
        ListNode* start = head;
        int count = 0;

        while(temp != NULL) {
            temp = temp->next;
            count++;
        } 

        for(int i=1 ; i<k ; i++) {
            start = start->next;
        }
        int store = start->val;

        for(int i=1 ; i<=count-k ; i++) {
            end = end->next;
        }

        start->val = end->val;
        end->val = store;

        return head;
    }
};