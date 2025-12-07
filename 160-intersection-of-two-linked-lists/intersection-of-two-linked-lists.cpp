class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        ListNode *t1 = head1, *t2 = head2;
        int c1 = 0, c2 = 0;

        while(t1) { c1++; t1 = t1->next; }
        while(t2) { c2++; t2 = t2->next; }

        int diff = abs(c1 - c2);

        if(c1 > c2) while(diff--) head1 = head1->next;
        else while(diff--) head2 = head2->next;

        while(head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }

        return head1; // or NULL if no intersection
    }
};
