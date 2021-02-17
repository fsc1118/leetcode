
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int hasCycle(struct ListNode *head) {
    struct ListNode* quickerPointer = head;
    struct ListNode* lowerPointer = head;
    int k = 0;
    if (head == 0)
        return 0;
    while (1){
        if (quickerPointer == lowerPointer && k != 0){
            return 1;
        }
        k=1;     
        quickerPointer = quickerPointer->next;
        if (quickerPointer == 0)
            return 0;
        quickerPointer = quickerPointer->next;
        if (quickerPointer == 0)
            return 0;
        lowerPointer = lowerPointer->next;
    }
}