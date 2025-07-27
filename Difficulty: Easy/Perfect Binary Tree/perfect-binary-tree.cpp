/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    bool isPerfect(Node *root) {
        // code here
        if(!root)return true;
        queue<Node*>q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int n=q.size();
            if(n!=pow(2,l))return false;
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
            l++;
        }
        
        return true;
    }
};