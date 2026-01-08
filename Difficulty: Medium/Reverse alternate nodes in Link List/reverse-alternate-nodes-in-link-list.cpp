class Solution {
  public:
  
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void rearrange(Node* head) {
        if (!head || !head->next) return;
        
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        
        // Separate odd and even nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = NULL;  // terminate odd list
        
        // Reverse even list
        Node* revEven = reverse(evenHead);
        
        // Append at end
        odd->next = revEven;
    }
};
