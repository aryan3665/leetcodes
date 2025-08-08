/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void helper(Node*root,int pos,int &l,int &r){
        if(root==NULL){
            return;
        }
        l=min(l,pos);
        r=max(r,pos);
        
        helper(root->left,pos-1,l,r);
        helper(root->right,pos+1,l,r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l=0;//leftmost node positon
        int r=0;//rightmost node position 
        helper(root,0,l,r);//here 0 is position
        vector<int>ans(r-l+1);
        vector<bool>vis(r-l+1,0);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(-1*l);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            int tempo =index.front();
            index.pop();
            
            
            if(!vis[tempo]){
                vis[tempo]=1;
                ans[tempo]=temp->data;
            }
            
            if(temp->left){
                q.push(temp->left);
                index.push(tempo-1);
                
            }
            
            if(temp->right){
                q.push(temp->right);
                index.push(tempo+1);
            }
        }
        return ans;
        
    }
};

