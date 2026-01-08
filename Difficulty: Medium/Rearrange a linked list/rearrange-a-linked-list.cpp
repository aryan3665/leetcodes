/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        
        if(head->next==NULL)return ;
        Node*odd=head;
        Node*even=head->next;
        Node*temp=even;
        while(even&&even->next){
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
        }
        odd->next=temp;
    }
};