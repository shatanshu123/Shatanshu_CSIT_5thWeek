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
private:
  // Algo to merge two lists in O(1) space
  ListNode *merge(ListNode *l1, ListNode *l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val < l2->val){
      l1->next = merge(l1->next, l2);
      return l1;
    }
    l2->next = merge(l1, l2->next);
    return l2;
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists){
    int in=1, en = lists.size();
    while(in<en){
	  //merging two consecutive lists at each step
      for(int i=0; i<en-in; i+=in*2)
        lists[i]=merge(lists[i], lists[i+in]);
      in*=2;
    }
    return lists.empty() ? NULL : lists[0];
  }
};