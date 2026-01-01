class myQueue {

  public:
  
  int k;
  int*arr;
  int front,rear;
    myQueue(int n) {
        // Define Data Structures
        arr=new int[n];
        k=n;
        front=-1;
        rear=-1;
    }

    bool isEmpty() {
        // check if the queue is empty
        
        if(front==-1)return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        
        if((rear+1)%k==front)return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isEmpty()){
            front=rear=0;
            arr[rear]=x;
        }
        else if(isFull()){
            return;
        }
        
        else{
            rear=(rear+1)%k;
            arr[rear]=x;
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return;
            
        }
        else {
            if(front==rear){
                front=rear=-1;
            }
            else{
                front=(front+1)%k;
                
            }
        }
         
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return -1 ;
            
        }
        
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
};