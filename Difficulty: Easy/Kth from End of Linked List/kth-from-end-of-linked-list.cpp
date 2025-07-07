/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int c=0;
    Node*curr=head;
    while(curr){
        c++;
        curr=curr->next;
    }
    if(k>c){
        return -1;
    }
    c=c-k;
    
    curr=head;
    while(c--){
        curr=curr->next;
    }
    return curr->data;
    
    
    }
};