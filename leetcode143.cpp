#include<stack>
#include<queue>
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
    void reorderList(ListNode* head) {
        if (head == 0)
            return;
        ListNode* quick = head;
        ListNode* slow = head;
        bool b = false;
        while (quick -> next != 0){
            quick = quick->next;
            if (b)
                slow = slow->next;
            b = !b;
        }
        ListNode* a = slow;
        slow = slow->next;
        //cout<<slow->val<<endl;
        stack<ListNode*> s;
        while (slow != 0){
            s.push(slow);
            slow = slow->next;
        }
        
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        while (!s.empty()){
            pointer2 = pointer1->next;
            ListNode* ln = s.top();
           // cout<<ln->val<<endl;
            ln->next = pointer2;
            s.pop();
            pointer1->next = ln;
            pointer1 = pointer2;
        }
        pointer1->next = 0;
    }
};