#include<stack>

using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int k;   
        while (1){
            int num = s1.top();
            s1.pop();      
            if (s1.empty()){
                k = num;
                break;
            }
            s2.push(num);
        } 
        while (!s2.empty()){
            int num = s2.top();
            s2.pop();
            s1.push(num);
        }
        return k;
        
        
    }
    
    /** Get the front element. */
    int peek() { 
        int k;   
        while (1){
            int num = s1.top();
            s1.pop();
            s2.push(num);      
            if (s1.empty()){
                k = num;
                break;
            }
            
        } 
        while (!s2.empty()){
            int num = s2.top();
            s2.pop();
            s1.push(num);
        }
        return k;
        

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */