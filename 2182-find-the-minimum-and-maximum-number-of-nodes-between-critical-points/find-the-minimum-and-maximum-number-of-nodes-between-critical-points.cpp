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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        vector<int>critical;
        ListNode* prev = temp;
        temp = temp->next;
        int count = 1;
        while(temp->next){
            if(temp->val > prev->val && temp->val > temp->next->val)
                critical.push_back(count);
            else if(temp->val < prev->val && temp->val < temp->next->val)
                critical.push_back(count);
            prev = temp;
            temp = temp->next;
            count++;
        }
        int maxi = INT_MIN,mini = INT_MAX;
        for(auto i:critical)
            cout<<i<<" ";
        for(int i=1;i<critical.size();i++){
            maxi = max(maxi,abs(critical[critical.size()-i] - critical[i-1]));
            mini = min(mini,abs(critical[i] - critical[i-1]));
        }
        if(maxi == INT_MIN) maxi = -1;
        if(mini == INT_MAX) mini = -1;
        return {mini,maxi};
    }
};