// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
  public:

    void create_tree(node* root0, vector<int>& vec) {
        // Your code goes here
         node * curr=root0;
       curr->left=newNode(vec[1]);
       curr->right=newNode(vec[2]);
       curr->left->left=newNode(vec[3]);
       curr->left->right=newNode(vec[4]);
       curr->right->left=newNode(vec[5]);
       curr->right->right=newNode(vec[6]);
    }
};