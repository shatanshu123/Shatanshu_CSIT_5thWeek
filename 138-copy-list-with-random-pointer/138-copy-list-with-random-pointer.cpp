/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* pointer = head;
        unordered_map<Node*, Node*> map;
    
        while(pointer != nullptr){
            Node* new_pointer = new Node(pointer->val);
            
            map[pointer] = new_pointer;
            pointer = pointer->next;
        }
        
        pointer = head;
        while(pointer != nullptr){
            map[pointer]->next = map[pointer->next];
            map[pointer]->random = map[pointer->random];
            pointer = pointer->next;
        }
        
        return map[head];
    }
    
};