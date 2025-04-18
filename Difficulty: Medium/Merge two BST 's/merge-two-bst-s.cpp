//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    // Function to perform inorder traversal and store elements in sorted order
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    // Merging two sorted vectors into a single sorted vector
    vector<int> mergeSortedVectors(vector<int>& v1, vector<int>& v2) {
        vector<int> ans;
        int l = 0, r = 0;
        
        while (l < v1.size() && r < v2.size()) {
            if (v1[l] < v2[r]) {
                ans.push_back(v1[l]);
                l++;
            } else if (v1[l]==v2[r]) {
                ans.push_back(v2[r]);
                 ans.push_back(v2[r]);
                 l++;
                r++;
            }
            else if(v1[l]>v2[r]){
                 ans.push_back(v2[r]);
                 r++;
            }
        }

        // Add remaining elements
        while (l < v1.size()) {
            ans.push_back(v1[l]);
            l++;
        }

        while (r < v2.size()) {
            ans.push_back(v2[r]);
            r++;
        }

        return ans;
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        return mergeSortedVectors(v1, v2);
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends