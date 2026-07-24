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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto i:lists){
            ListNode* temp = i;
            while(temp){
                q.push(temp->val);
                temp = temp->next;
            }
        }
        if(q.empty()) return nullptr;
        ListNode* head = new ListNode(q.top());
        ListNode* prev = head;
        q.pop();
        while(!q.empty()){
            ListNode* newnode = new ListNode(q.top());
            q.pop();
            prev->next = newnode;
            prev = newnode;
        }
        return head;
    }
};