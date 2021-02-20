/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stack>
using namespace std;

  class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while (l1 != 0){
            stack1.push(l1);
            l1 = l1->next;
        }
        while (l2 != 0){
            stack2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* pointer = 0;
        while (!stack1.empty() || !stack2.empty()){
            int num1 = 0;
            int num2 = 0;
            if (!stack1.empty()){
                ListNode* one = stack1.top();
                stack1.pop();
                num1 = one->val;
            }
            if (!stack2.empty()){
                ListNode* two = stack2.top();
                stack2.pop();
                num2 = two->val;
            }
            int val = (num1 + num2 + carry) % 10;
            cout<<val<<endl;
            ListNode* ln = new ListNode();
            ln->val = val;
            ln->next = pointer;
            pointer = ln;
            carry = (num1 + num2 + carry >= 10) ? 1:0;
            //cout<<carry<<endl;
        }
        if (carry == 1){
            //cout<<"jere"<<endl;
            ListNode* ln = new ListNode(1);
            ln->next = pointer;
            return ln;
        }
        return pointer;
    }
};