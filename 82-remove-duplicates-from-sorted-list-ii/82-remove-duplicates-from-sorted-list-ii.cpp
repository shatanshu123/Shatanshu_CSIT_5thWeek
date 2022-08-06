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
     ListNode* deleteDuplicates(ListNode* head) {
       
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* newDummy = dummy;
        while(curr != nullptr) {
            ListNode* temp = curr;
            int cnt = 0;
            while(curr != nullptr and curr->val == temp->val) {
                curr = curr->next;
                cnt++;
            }
            
            if(cnt == 1) {
                newDummy->next = new ListNode(temp->val);
                newDummy =  newDummy->next;
            }
            
        }
        

       
        
        return dummy->next;
       
        
        
    }
};