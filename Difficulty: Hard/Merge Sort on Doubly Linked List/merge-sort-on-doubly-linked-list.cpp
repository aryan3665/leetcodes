/* Structure of the node of the list is as
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
   DLLNode*mids(DLLNode*head){
      DLLNode*slow=head;
      DLLNode*fast=head->next;
      while(fast&&fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
     
      return slow;
  }
  
  
  DLLNode*mergesortedlist(DLLNode*left,DLLNode*right){
        DLLNode*head = new DLLNode(0);   // dummy node
    DLLNode* tail = head;
    DLLNode*pre=head;

    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            tail->next->prev=tail;
            left = left->next;
        } else {
            tail->next = right;
              tail->next->prev=tail;
            right = right->next;
        }
        tail = tail->next;
        tail->next = NULL;
    }

    if (left) {
        tail->next = left;
        tail->next->prev=tail;
    } else {
        tail->next = right;
        tail->next->prev=tail;
    }

    DLLNode* temp = head;
    head = head->next;
    delete temp;
    head->prev=NULL;

    return head;
  }
  
  
    DLLNode *sortDoubly(DLLNode *head) {
        // Your code here
         if (!head || !head->next) return head;
         DLLNode*mid=mids(head);
        DLLNode*newhead=mid->next;
        newhead->prev=NULL;
        mid->next=NULL;
        
        DLLNode*left=sortDoubly(head);
        DLLNode*right=sortDoubly(newhead);
        return mergesortedlist(left,right);
        
    }
};