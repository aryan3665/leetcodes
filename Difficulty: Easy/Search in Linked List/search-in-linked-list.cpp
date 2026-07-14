/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
         // Code here
        Node *ptr=head;
        bool f=0;
        while(ptr!=NULL){
            if(ptr->data==key){
                f=1;
                break;
            }
            ptr=ptr->next;
        }
        return f;
    }
};
