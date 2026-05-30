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
    int nodeCount(ListNode* head)
    {
        int count =0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count ++;
            temp = temp->next;
        }
    return count;
    }

    ListNode* middleNode(ListNode* head) {
        int count = nodeCount(head);

        int middle = count /2;

        int counter =0;

        while(counter < middle)
        {
            head= head->next;
            counter ++;
        }

    return head;
    }
};
