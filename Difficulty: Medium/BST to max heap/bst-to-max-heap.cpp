// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
public:
    void inorder(Node* root, vector<int>& ino) {
        if (!root) return;
        inorder(root->left, ino);
        ino.push_back(root->data);
        inorder(root->right, ino);
    }

    void postorderFill(Node* root, vector<int>& ino, int& i) {
        if (!root) return;
        postorderFill(root->left, ino, i);
        postorderFill(root->right, ino, i);
        root->data = ino[i++];
    }

    void convertToMaxHeapUtil(Node* root) {
        vector<int> ino;
        inorder(root, ino); // Step 1: Get sorted elements
        int i = 0;
        postorderFill(root, ino, i); // Step 2: Fill tree in postorder
    }
};

