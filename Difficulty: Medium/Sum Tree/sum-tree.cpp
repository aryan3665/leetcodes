class Solution {
public:
    int sum(Node* root) {
        if (!root) return 0;
        return root->data + sum(root->left) + sum(root->right);
    }

    bool issum(Node* root) {
        if (!root || (!root->left && !root->right)) return true; // leaf or empty

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        if (root->data != leftSum + rightSum) return false;

        return issum(root->left) && issum(root->right);
    }

    bool isSumTree(Node* root) {
        return issum(root);
    }
};
