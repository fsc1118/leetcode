#include<queue>
using namespace std;
class MyStack {
    queue<int> q1;
    queue<int> q2;
    int size = 0;
    bool q1_or_q2 = true; //true for q1 and false for q2
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1_or_q2 ? q1.push(x) : q2.push(x);
        size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int count = 1;
        cout<<size<<endl;
        while (count < size){
            count++;
            if (q1_or_q2){
                auto c = q1.front();
                q2.push(c);
                q1.pop();
            } else{
                auto c = q2.front();
                q1.push(c);
                q2.pop();
            }
        }
        int i = q1_or_q2 ? q1.front() : q2.front();
       // cout<<i<<endl;
        q1_or_q2 ? q1.pop() : q2.pop();
        q1_or_q2 = !q1_or_q2;
        size--;
        return i;
    }
    
    /** Get the top element. */
    int top() {
        int count = 1;
        
        while (count < size){
          //  cout<<12<<endl;
            count++;
            if (q1_or_q2){
                auto c = q1.front();
               // cout<<q2.empty()<<endl;
                q2.push(c);
                q1.pop();
            } else{
                auto c = q2.front();
                q1.push(c);
                q2.pop();
            }
        }
        int i = q1_or_q2 ? q1.front() : q2.front();
        q1_or_q2 ? q2.push(i) : q1.push(i);
        q1_or_q2 ? q1.pop() : q2.pop();
        q1_or_q2 = !q1_or_q2;
        return i;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */