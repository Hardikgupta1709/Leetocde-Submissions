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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
        {
            return head;
        }
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        int n =0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        k = k%n;
        if(k==0)
        {
            return head;
        }

        int count =0;
        ListNode* tail = head;
        ListNode* prev = NULL;

        while(count != k)
        {
            tail = head;      
            prev = NULL; 
            while(tail->next != NULL)
            {
                prev = tail;
                tail = tail->next;
            }

            tail->next = head;
            head = tail;
            prev->next = NULL;

            count ++;
        }
    return head;
    }
};
