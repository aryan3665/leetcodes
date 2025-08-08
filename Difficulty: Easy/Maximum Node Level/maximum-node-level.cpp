/*Complete the function below
Node is as follows:
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

    // Return the level (0-indexed) with maximum number of nodes.
    int maxNodeLevel(Node *root) {
        // Add your code here
        queue<Node*>q;
        q.push(root);
        int maxi=INT_MIN;
        int level=0;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            if(maxi<n){
                maxi=n;
                ans=level;
            }
            while(n--){
                Node*temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
        }
        return ans;
    }
};