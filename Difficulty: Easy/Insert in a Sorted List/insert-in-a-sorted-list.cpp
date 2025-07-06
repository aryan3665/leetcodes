class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        Node* temp = new Node(key);

        // Case 1: Empty list or insert at head
        if (!head || key < head->data) {
            temp->next = head;
            return temp;
        }

        // Case 2: Traverse to find the insertion point
        Node* curr = head;
        while (curr->next && curr->next->data < key) {
            curr = curr->next;
        }

        // Insert after current
        temp->next = curr->next;
        curr->next = temp;

        return head;
    }
};
