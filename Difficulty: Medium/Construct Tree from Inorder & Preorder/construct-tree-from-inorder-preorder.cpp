//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
      int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1; // Target not found
    }

    Node* tree(vector<int>& inorder, vector<int>& preorder, int instart, int inend, int index) {
        if (instart > inend) {
            return NULL; // Base case
        }

        // Check if index is valid
        if (index < 0 || index >= preorder.size()) {
            return NULL; // Handle out-of-bounds access
        }

        Node* root = new Node(preorder[index]);
        int pos = find(inorder, preorder[index], instart, inend);

        // Check if position is valid
        if (pos == -1) {
            // Handle error: target not found in inorder
            return NULL; // or throw an exception
        }

        root->left = tree(inorder, preorder, instart, pos - 1, index + 1);
        root->right = tree(inorder, preorder, pos + 1, inend, index + (pos - instart + 1));

        return root;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // Code here
        
        if (preorder.empty() || inorder.empty()) {
            return NULL; // Return NULL for empty input
        }
        
        int n = preorder.size();
        return tree(inorder, preorder, 0, n - 1, 0);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends