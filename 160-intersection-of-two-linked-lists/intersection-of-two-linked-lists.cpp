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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(true){
            if(a == b) return a;
            else if(a == nullptr) a = headB;
            else if(b == nullptr) b = headA;
            else{
                a = a->next;
                b = b->next;
            }
        }
        return nullptr;
    }
};