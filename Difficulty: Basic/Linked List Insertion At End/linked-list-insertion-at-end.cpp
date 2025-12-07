/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(!head){
            Node*head=new Node(x);
            return head;
        }
        // Code here
        Node*temp=head;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(x);
        return head;
        
    }
};