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

    int counting (ListNode* head)
    {
        int count =0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            count++;
            temp= temp->next;
        }
    return count;
    }

    ListNode* swapNodes(ListNode* head, int k) {

       if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int count = counting(head);
        int pos =1;
        int o1 =k;
        int o2 = count -k+1;

        if(o1 == o2)
        {
            return head;
        }

        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;
        ListNode* node1 = head;
        ListNode* node2 = head;



        for(int i=1; i< o1; i++)
        {
            prev1 = node1;
            node1= node1->next;
        }
        for(int i=1; i<o2; i++)
        {
            prev2 = node2;
            node2= node2->next;
        }

        if(prev1)
        {
        prev1 ->next = node2;
        }
        else
        {
            head = node2;
        }

        if(prev2)
        {
        prev2 ->next = node1;
        }
        else
        {
            head = node1;
        }

        ListNode* tempNext = node1->next;
        node1->next = node2->next;
        node2->next = tempNext;

    return head;
    }
};
