class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Finding the middle element
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle
        if (prev != NULL) prev->next = NULL;

        // Create root with the middle element
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left subtree only if middle is not the first element
        if (slow != head) root->left = sortedListToBST(head);

        // Recursively build right subtree
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
