class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (head == NULL || k == 0) return head;

        // Step 1: Count nodes
        int count = 0;
        Node* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // Step 2: Normalize k
        k = k % count;
        if (k == 0) return head;

        // Step 3: Reach the kth node
        curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        // Step 4: Break and rotate
        Node* newHead = curr->next;
        curr->next = NULL;

        // Step 5: Attach end to old head
        Node* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};
