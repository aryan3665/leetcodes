/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node*slow=head;
        Node*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(!fast||!fast->next){
            return 0;
        }
        
        int c=1;
        slow=fast->next;
        while(slow!=fast){
            slow=slow->next;
            c++;
        }
        return c;
    }
};