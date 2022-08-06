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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }
            ListNode*slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            
            ListNode*prev=NULL,*curr=slow,*temp; 
            while(curr){
               temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
			//Merging the lists
            ListNode*n1=head,*n2=prev;
            while(n2->next){
                temp=n1->next;
                n1->next=n2;
                n1=temp;
                
                temp=n2->next;
                n2->next=n1;
                n2=temp;
                }
   
    }
    
};
