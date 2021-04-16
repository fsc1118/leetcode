/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* pointer = head; pointer != 0;){
            if (pointer->child != 0){
                Node* next = pointer->next;
                pointer->next = flatten(pointer->child);
                pointer->child = 0;
                while (pointer->next != 0){          
                    pointer->next->prev = pointer;
                    pointer = pointer->next;
                }
                pointer->next = next;
                if (next != 0)
                    next->prev = pointer;
                pointer = next;
            } else{
                pointer = pointer->next;
            }
        }
        return head;
    }
};