/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    int fractional_node(struct Node *head, int k) {
        // your code here
        if(!head)return NULL;
        int c=0;
        Node*curr=head;
        while(curr->next!=NULL){
            c++;
            curr=curr->next;
        }
        int x=ceil(c/k);
        curr=head;
       
        
        while(x--){
        
            curr=curr->next;
        }
      return curr->data;
    }
};