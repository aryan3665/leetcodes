class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        if (!head) return NULL;
        if (head->next == NULL) return head;

        Node* curr = head->next;

        while (curr != NULL) {   // bas yahi change
            if (curr->data == curr->prev->data) {
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = curr->prev;
            }
            curr = curr->next;
        }
        return head;
    }
};
