// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
        // code here
        if(!head){
            return NULL;
        }
        Node*curr=head;
        Node*pre=NULL;
        while(curr->next!=NULL){
            pre=curr;
            curr=curr->next;
        }
        pre->next=NULL;
        curr->next=head;
        head=curr;
        return head;
    }
};