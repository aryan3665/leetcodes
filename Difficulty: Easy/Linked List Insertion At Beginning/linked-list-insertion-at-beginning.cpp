// User function Template for C++

class Solution {
  public:
    // Function to insert a node at the begining of the linked list.
    Node *insertAtBegining(Node *head, int x) {
        // Code here
        Node*temp=new Node(x);
        if(!head){
            return temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        return head;
    }
};