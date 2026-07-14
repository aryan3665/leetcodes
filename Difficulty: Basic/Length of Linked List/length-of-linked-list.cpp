/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
int c=0;
if(!head)return 0;
        // Code here
        Node*curr=head;
        while(curr){
            c++;
            curr=curr->next;
        
        }
        return c;
        
    }
};