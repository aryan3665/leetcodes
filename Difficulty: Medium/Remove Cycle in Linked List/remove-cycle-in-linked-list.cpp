/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
   void removeLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    // Detect cycle

    while (fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No cycle

    if (fast == NULL || fast->next == NULL)
        return;

    // Find starting point

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Reach last node of cycle

    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL;
}
};