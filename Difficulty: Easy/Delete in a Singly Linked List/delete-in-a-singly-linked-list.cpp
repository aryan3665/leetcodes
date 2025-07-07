/* Link list Node
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
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        
         if(head->next==NULL){ 
        Node*temp=head;
        head=NULL;
        
        delete temp;
        return head;
        
    }
        Node*curr=head;
        Node*pre=NULL;
        if(x==1){
            Node*temp=head;
            head=head->next;
            delete temp;
            
        }
        else{
            x--;
        
        while(x--){
            pre=curr;
            curr=curr->next;
        }
        pre->next=curr->next;
        delete curr;
        }
        return head;
        
    }
};