/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
         Node* new_node = new Node(x);
         if (head == nullptr) {
        return new_node;
    }
     Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next pointer of the last node 
    // to point to the new node
    last->next = new_node;

    // Return the head of the list
    return head;
    }
};