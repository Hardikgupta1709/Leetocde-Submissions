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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;

        while(head!= NULL)
        {
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;

        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* head = new ListNode(0);
        ListNode* ans = head;

        int carry =0;
        
        while(l1 != NULL || l2 != NULL || carry)
        {
            int sum = carry;
            if(l1 !=NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 !=NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum%10;
            carry  = sum/10;

            if(l1 != NULL || l2!= NULL || carry)
            {
                ans->next = new ListNode(0);
                ans = ans->next;
            }
        }

    return reverse(head);
    }
};
