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
        ListNode* temp = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;

        while(temp != NULL)
        {
            forward = temp->next;
            if(temp->val == val)
            {
                if(prev == NULL)
                {
                    head= forward;
                }
                else
                {
                    prev->next = forward;
                }
            }
            else
            {
                prev= temp;
            }
            temp = forward;
        }
    return head;
    }
};
