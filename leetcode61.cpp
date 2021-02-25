#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int length = 0;
        ListNode* ln = head;
        stack<ListNode*> s;
        while (ln != 0) {
            s.push(ln);
            ln = ln->next;
            length++;
        }
        length = k % length;
        if (length == 0)
            return head;
        //cout<<length<<endl;
        stack<ListNode*> another;
        for (int i = 1; i <= length; i++){
            another.push(s.top());
            s.pop();
        }
        s.top()->next = 0;
        ListNode* newHead = 0;
        ListNode* pointer1 = newHead;
        ListNode* pointer2 = newHead;
        int h = 0;
        while(!another.empty()){
            ListNode* p = another.top();
            another.pop();
            if (h == 0){
                newHead = p;
                pointer1 = newHead;
                pointer2 = pointer1;
                h++;
            } else {
                pointer1 = p;
                pointer2->next = pointer1;
                pointer2 = pointer1;
            }
        }
        pointer2->next = head;
        return newHead;
    }
};