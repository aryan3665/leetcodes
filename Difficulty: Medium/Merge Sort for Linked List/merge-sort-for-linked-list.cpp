/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  Node*mids(Node*head){
      Node*slow=head;
      Node*fast=head->next;
      while(fast&&fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
     
      return slow;
  }
  
  
  Node*mergesortedlist(Node*left,Node*right){
        Node* head = new Node(0);   // dummy node
    Node* tail = head;

    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
        tail->next = NULL;
    }

    if (left) {
        tail->next = left;
    } else {
        tail->next = right;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
  }
    Node* mergeSort(Node* head) {
        // code here
        
        if (!head || !head->next) return head;
        Node*mid=mids(head);
        Node*newhead=mid->next;
        mid->next=NULL;
        
        Node*left=mergeSort(head);
        Node*right=mergeSort(newhead);
        return mergesortedlist(left,right);
        
    }
};