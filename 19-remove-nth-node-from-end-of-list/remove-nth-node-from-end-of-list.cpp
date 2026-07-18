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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(!head) return nullptr;
        if(!head->next) return nullptr;

        int pos = len - n + 1;
        int k = 1;

        if(pos == 1){
            head = head->next;
            return head;
        }

        ListNode* temp2 = head;
        while(k < pos - 1){
            temp2 = temp2->next;
            k++;
        }
        ListNode* del = temp2->next;
        if(del->next)
        temp2->next = del->next;
        else
        temp2->next = nullptr;
        delete del;
        return head;
    }
};