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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* LL_To_BST(ListNode* &head , int n) {
        if(head == NULL || n == 0) {
            return NULL;
        }
        //L
        TreeNode* leftSubtree = LL_To_BST(head , n/2);
        //N
        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubtree;
        head = head->next;

        TreeNode* rightSubtree = LL_To_BST(head , n- n/2 -1);
        root->right = rightSubtree;

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }

        return LL_To_BST(head , n);
    }
};