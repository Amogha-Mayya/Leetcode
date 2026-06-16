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
ListNode* reverse_ll(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* fwd = nullptr;
    while(curr){
        fwd = curr->next;
        curr->next = prev;

        prev = curr;
        curr = fwd;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverse_ll(slow->next);
        slow->next = nullptr;
        // merge linked list accordingly
        while(head && head2){
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2->next;

            head->next = head2;
            head2->next = temp1;

            head = temp1;
            head2 = temp2;
        }
    }
};