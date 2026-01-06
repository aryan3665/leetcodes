/*
Structure of the node of the linked list is as
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        set<int>mp;
        Node*temp=head1;
        while(temp){
            mp.insert(temp->data);
            temp=temp->next;
        }
        temp=head2;
        int count=0;
        while(temp){
            int finde=x-temp->data;
            if(mp.find(finde)!=mp.end())count++;
            temp=temp->next;
        }
        return count;
        
    }
};