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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        vector<int> ans;

        ListNode* temp = head;
        ListNode* temp2 = head->next;

        while(temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
            if(temp != NULL) {
                temp = temp->next;
            }
            
        }
        

        while(temp2 != NULL) {
            ans.push_back(temp2->val);
            temp2 = temp2->next;
            if(temp2 != NULL) {
                temp2 = temp2->next;
            }
            
        }

        ListNode* res = head;

        int n = ans.size();

        for(int i=0 ; i<n ; i++) {
            res->val = ans[i];
            res = res->next;
        }

        return head;
    }
};