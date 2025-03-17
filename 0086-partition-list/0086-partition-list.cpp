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
    vector<int> small;
    vector<int> large;
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) {
                small.push_back(temp->val);
            }
            else {
                large.push_back(temp->val);
            }
            temp = temp->next;
        }

        temp = head;

        for(int i=0 ; i<large.size(); i++) {
            small.push_back(large[i]);
        }

        for(int i=0 ; i<small.size() ; i++) {
            temp->val = small[i];
            temp = temp->next;
        }
        return head;
    }
};