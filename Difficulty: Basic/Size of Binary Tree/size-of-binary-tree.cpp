/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* root) {
        // code here
   int ans=0;

       

        // Queue for level-order traversal
        queue<Node*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at current level
            ans+=n;
     

            // Process all nodes of the current level
            while(n--) {
                Node* fronty = q.front(); // Get the front node
                q.pop(); // Remove it from the queue

              

                // Push left child if exists
                if (fronty->left)
                    q.push(fronty->left);

                // Push right child if exists
                if (fronty->right)
                    q.push(fronty->right);
            }

         
           
        }

        return ans;
    }
};