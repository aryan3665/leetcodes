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
  Node*reverse(Node*temp){
      
      if(!temp->next)return temp;
      Node*curr=temp->next;
      Node*prev=temp;
      Node*fut;
      while(curr){
          fut=curr->next;
          curr->next=prev;
          prev->next=fut;
          prev=curr;
          curr=fut;
      }
      
      
      temp=prev;
      return temp;
  }
bool isPalindrome(Node *head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd length, skip middle node
    if (fast) slow = slow->next;

    // Reverse second half
    Node* head2 = reverse(slow);

    // Compare both halves
    Node* head1 = head;
    while (head2) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

};