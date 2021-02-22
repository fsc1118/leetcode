class MyLinkedList {
    class Node{
       
        public:
        Node(int val){
            this->val = val;
            prev = 0;
            next = 0;
        }
        int val;
        Node* prev;
        Node* next;
    };
    int currentSize;
    Node* head;
    Node* back;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        currentSize = 0;
        head = 0;
        back = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= currentSize)
            return -1;
        int count = 0;
        Node* tempPointer = head;
        while (count != index){
            tempPointer = tempPointer->next;
            count++;
        }
        return tempPointer->val;

    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        currentSize++;
        if (head == 0){ //empty
            head = node;
            back = node;
        } else{
            node->next = head;
            head->prev = node;
            head = node;
        }

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        node->next = 0;
        currentSize++;
        if (back == 0){ //empty
            head = node;
            back = node;
        } else{
            node->prev = back;
            back->next = node;
            back = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0)
            return addAtHead(val);
        if (index > currentSize)
            return;           
        if (index == currentSize)
            return addAtTail(val);
        int count = 0;
        Node* tempPointer = head;
        while (count != index){
            tempPointer = tempPointer->next;
            count++;
        }
        currentSize++;
        Node* n = tempPointer->prev;
        Node* n1 = tempPointer;
        Node* newNode = new Node(val);
        n->next = newNode;
        n1->prev = newNode;
        newNode->prev = n;
        newNode->next = n1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
       // cout<<1<<endl;
        if (index < 0 || index >= currentSize)
            return;
        if (currentSize == 1){
            back = 0;
            head = 0;
            return;
        }
        if (index == 0){
            Node* temp = head->next;
            head->next = 0;
            temp->prev = 0;
            head = temp;
        } else if (index == currentSize - 1){
            Node* temp = back->prev;
            temp->next = 0;
            back->prev = 0;
            back = temp;
        } else{
           // cout<<currentSize<<endl;
            int count = 0;
            Node* tempPointer = head;
            while (count != index){
                tempPointer = tempPointer->next;
                count++;
            }
            Node* temp = tempPointer->prev;
            Node* temp2 = tempPointer->next;
            tempPointer->prev = 0;
            tempPointer->next = 0;
            temp->next = temp2;
            temp2->prev = temp;
        }
        currentSize--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */