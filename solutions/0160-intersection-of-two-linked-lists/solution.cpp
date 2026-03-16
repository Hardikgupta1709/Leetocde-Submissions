/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int length(ListNode *node)
    {
        int count =0;

        while(node != NULL)
        {
            count ++;
            node = node->next;
        }
    return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = length(headA);
        int lenB = length(headB);
        
        ListNode * currA = headA;
        ListNode * currB = headB;

        int diff = abs(lenA - lenB);

        if(lenA > lenB)
        {
            while(diff--)
            {
                currA = currA->next;
            }
        }        
        else
        {
            while(diff--)
            {
                currB = currB->next;
            }
        }

        while(currA != NULL && currB != NULL)
        {
            if(currA == currB)
            {
                return currA;
            }
            else
            {
                currA= currA->next;
                currB= currB->next;
            }
        }
    return NULL;
    }
};
