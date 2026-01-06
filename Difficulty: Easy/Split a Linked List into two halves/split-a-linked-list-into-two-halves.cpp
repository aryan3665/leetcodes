class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (!head || head->next == head)
            return {head, NULL};

        Node *slow = head, *fast = head;

        // Find middle using slow-fast
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For even number of nodes
        if (fast->next->next == head)
            fast = fast->next;

        Node* head1 = head;
        Node* head2 = slow->next;

        // Make first half circular
        slow->next = head1;

        // Make second half circular
        fast->next = head2;

        return {head1, head2};
    }
};
