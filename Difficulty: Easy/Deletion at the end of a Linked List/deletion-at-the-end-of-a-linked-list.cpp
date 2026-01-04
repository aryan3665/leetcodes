/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        // code here
        if(!head){
          return NULL;  
        }
        else if(head->next==NULL){
            delete head;
            return NULL;
        }        
        
        Node*temp=head;
        Node*prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        delete temp;
        prev->next=NULL;
        
        return head;
    }
};