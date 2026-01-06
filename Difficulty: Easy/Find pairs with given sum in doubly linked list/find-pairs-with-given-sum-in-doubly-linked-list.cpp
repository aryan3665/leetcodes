// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>>ans;
        Node*start=head;
        Node*end=head;
        while(end&&end->next!=NULL){
            end=end->next;
        }
        
        while(start->data<end->data){
            if(start->data+end->data==target){
                ans.push_back({start->data,end->data});
                start=start->next;
                end=end->prev;
            }
            else if((start->data+end->data)>target){
                end=end->prev;
            }
            else{
                start=start->next;
            }
        }
        
        return ans;
    }
};