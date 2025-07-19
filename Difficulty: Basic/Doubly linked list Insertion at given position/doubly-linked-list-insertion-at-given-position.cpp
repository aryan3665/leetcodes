class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* temp = new Node(data);
        Node* curr = head;

        // Move to the node at position `pos`
        while (pos-- > 0 && curr != NULL) {
            curr = curr->next;
        }

        if (curr == NULL) {
            // Position is out of bounds; do nothing
            return head;
        }

        // Insert after `curr`
        temp->next = curr->next;
        temp->prev = curr;

        if (curr->next != NULL) {
            curr->next->prev = temp;
        }
        curr->next = temp;

        return head;
    }
};
