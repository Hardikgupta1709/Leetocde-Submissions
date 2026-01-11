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

    ListNode* solve(ListNode* head, int left, int right)
    {
        ListNode * temp = head;
        ListNode * leftPrev = NULL;
        ListNode * leftHead = NULL;
        ListNode * leftLast = NULL;
        ListNode * remaining = NULL;
        ListNode * prev = NULL;
        ListNode * forward = NULL;

        int pos =1;
        while(temp != NULL)
        {
            if(pos == left-1)
            {
                leftPrev= temp;
            }
            if(pos == left)
            {
                leftHead= temp;
            }
            if(pos == right)
            {
                leftLast = temp;
                remaining = temp->next;
                break;
            }
            temp = temp->next;
            pos++;
        }

        
        temp = leftHead;   

        while (temp != remaining)
        {
            forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }

        if (leftPrev != NULL)
        {
            leftPrev->next = leftLast;
        }
        else
        {
                head = leftLast;
        }

        leftHead->next = remaining;

return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (head == NULL || head->next == NULL || left == right)
            {
                return head;
            }

        return solve(head,left,right);
    }
};
