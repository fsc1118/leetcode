struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* quickPointer = head;
        ListNode* slowPointer2 = head;
        while (quickPointer != 0){
            
            if (quickPointer->val == slowPointer2->val){
                quickPointer = quickPointer->next;
                continue;
            }
            slowPointer2->next = quickPointer;
            slowPointer2 = quickPointer;
            quickPointer = quickPointer->next;
        }
        if (slowPointer2 != 0)
            slowPointer2->next = 0;
        return head;
        
    }
};