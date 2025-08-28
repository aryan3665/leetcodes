
class Solution {
  public:
    // Function to delete a node from BST.
    Node *deleteNode(Node *root, int X) {
        // your code goes here
        if(!root)return NULL;
        if(X<root->data){
           root->left=deleteNode(root->left,X);
           return root;
        }
         else if(X>root->data){
           root->right=deleteNode(root->right,X);
           return root;
        }
        else{
            if(!root->left&&!root->right){
                delete root;
                return NULL;
                
            }
             else if(!root->left){
                   Node*temp=root->right;
                   delete root;
                   return temp;
                }
                else if(!root->right){
                    Node*temp=root->left;
                   delete root;
                   return temp;
                }
                else{
                    Node*child=root->left;
                    Node*parent=root;
                    while(child->right){
                        parent=child;
                        child=child->right;
                    }
                    if(root!=parent){
                        parent->right=child->left;
                        child->left=root->left;
                        child->right=root->right;
                        delete root;
                        return child;
                    }
                    else{
                        child->right=root->right;
                        delete root;
                        return child;
                    }
                }
    }
    }
};

