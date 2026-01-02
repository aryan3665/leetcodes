/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
  Node*top;
  int s;
    myStack() {
        // Initialize your data members
        s=0;
        top=NULL;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node*temp=new Node(x);
        temp->next=top;
        top=temp;
        s++;
    }

    void pop() {
        // Removes the top element of the stack
        if(!isEmpty()){
            Node *temp=top;
            top=top->next;
            delete temp;
            s--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(!isEmpty()){
            return top->data;
        }
        return -1;
    }

    int size() {
        // Returns the current size of the stack.
        return s;
    }
};