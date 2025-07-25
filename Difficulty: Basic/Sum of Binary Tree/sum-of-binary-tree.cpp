/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
      int sum=0;

    

        // Queue for level-order traversal
        queue<Node*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at current level
            vector<int> temp; // To store current level values

            // Process all nodes of the current level
            while(n--) {
                Node* fronty = q.front(); // Get the front node
                sum+=fronty->data;
                q.pop(); // Remove it from the queue

               
                // Push left child if exists
                if (fronty->left)
                    q.push(fronty->left);

                // Push right child if exists
                if (fronty->right)
                    q.push(fronty->right);
            }

         
    
        }

        return sum; 
    }
};