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
    vector<int> nodesAtOddLevels(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        queue<Node*>q;
        q.push(root);
        int l=1;
        while(!q.empty()){
            int n=q.size();
                while(n--){
                    Node*temp=q.front();
                    q.pop();
                    if(l%2!=0){
                        ans.push_back(temp->data);
                    }
                    
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
                l++;
            }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};