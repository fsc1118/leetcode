#include <stack>
#include <vector>
using namespace std;

typedef struct nodeWithIndex {
    int val;
    int index;
} nodeWithIndex;


class Solution {
private:
    int size(ListNode* head) {
        int i = 0;
        while (head != NULL) {
            i++;
            head = head->next;
        }
        return i;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int size = this->size(head);
        vector<int>* v = new vector<int>(size);
        stack<nodeWithIndex*> q;
        int index = 0;
        for (;head != NULL; head = head->next, index++) {
            while (1) {
                if (q.empty() || head->val <= q.top()->val) {
                    nodeWithIndex* nwi = new nodeWithIndex();
                    nwi->index = index;
                    nwi->val = head->val;
                    q.push(nwi);
                    break;
                } 
                if (head->val > q.top()->val) {
                    int index = q.top()->index;
                    delete(q.top());
                    q.pop();
                    (*v)[index] = head->val;
                }
            }
        }
        while (q.empty() == false) {
            int index = q.top()->index;
            delete(q.top());
            q.pop();
            (*v)[index] = 0;
        }
        return *v;
    }
};