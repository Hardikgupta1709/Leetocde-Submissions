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

    int count(ListNode* head)
    {
        int count =0;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            count ++;
            temp =temp->next;
        }
    return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

         
        int totalCount = count(head);
        if (n == totalCount)
        {
            return head->next;
        }
        int finalPos = (totalCount -n);

        ListNode * temp = head;
        
        for(int i=1; i<finalPos; i++)
        {
            temp=temp->next;
        }
        
        ListNode * remove = temp->next;
        ListNode * forward = remove->next;
        temp->next = forward;
return head;
    }
};
