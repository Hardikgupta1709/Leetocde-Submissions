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
    ListNode* insertionSortList(ListNode* head) {

        ListNode* sorted = head;
        ListNode* i = head->next;
        sorted->next = NULL;

        while(i != NULL)
        {
            ListNode* iprev = NULL;
            ListNode* j = sorted;
            int key = i->val;

            ListNode* nexti = i->next;

            while(j !=NULL && j->val < key)
            {
               iprev = j;
               j = j->next;
            }
            if(iprev == NULL)
            {
                i->next = sorted;
                sorted =i;
            }
            else
            {
                i->next = j;
                iprev->next =i;
            }
        i = nexti;
        }
return sorted;
}
};

