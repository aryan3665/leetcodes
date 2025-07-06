/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head==NULL){
            head=new Node(x);
            return head;
        }
        else{
            Node*temp=new Node(x);
            Node*tail=head;
            while(tail->next!=NULL){
                tail=tail->next;
            }
            tail->next=temp;
            temp->next=NULL;
        }
        return head;
    }
};