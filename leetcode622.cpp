class MyCircularQueue {
    class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
        }
        
    };
    int size;
    int currentNumber;
    Node* front;
    Node* back;
public:
    MyCircularQueue(int k) {
        size = k;
        currentNumber = 0;
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        Node* node = new Node(value);
        
        
        if (isEmpty()){
            currentNumber++;
            //cout<<1<<endl;
            back = node;
            front = node;
            return true;
        }
        currentNumber++;
        back->next = node;
        (*node).next = front;
        back = back->next;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        Node* temp = front; //element to be removed
        front = front->next; //new front
        temp->next = 0;
        back->next = front;
        currentNumber--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:front->val;
    }
    
    int Rear() {
        //cout<<back->val;
        return isEmpty()?-1:back->val;
    }
    
    bool isEmpty() {
        return currentNumber == 0;
    }
    
    bool isFull() {
        return currentNumber == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */