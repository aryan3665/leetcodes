class myStack {
public:
    int top;
    int k;
    int* stack;

    myStack(int n) {
        k = n;
        top = -1;
        stack = new int[k];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == k - 1;
    }

    void push(int x) {
        if (!isFull()) {
            stack[++top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return stack[top];
        }
        return -1; // or throw an exception
    }

    ~myStack() {
        delete[] stack;
    }
};
