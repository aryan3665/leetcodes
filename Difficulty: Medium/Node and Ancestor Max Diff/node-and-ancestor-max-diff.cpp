/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:

    int f(Node* root, int& maxim) {

        // Base case
        if(root == NULL)
            return INT_MAX;

        // Find minimum in left subtree
        int leftmin = f(root->left, maxim);

        // Find minimum in right subtree
        int rightmin = f(root->right, maxim);

        // Current node with minimum descendant
        if(root->left)
            maxim = max(maxim, root->data - leftmin);

        if(root->right)
            maxim = max(maxim, root->data - rightmin);

        // Return minimum value in current subtree
        return min({root->data, leftmin, rightmin});
    }

    int maxDiff(Node* root) {

        int maxim = INT_MIN;

        f(root, maxim);

        return maxim;
    }
};