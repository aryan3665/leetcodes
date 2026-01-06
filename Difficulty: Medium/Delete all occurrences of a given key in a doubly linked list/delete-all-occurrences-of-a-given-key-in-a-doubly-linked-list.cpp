class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {

        Node* temp = *head_ref;

        while (temp != NULL) {

            if (temp->data == x) {
                Node* del = temp;

                // agar head delete ho rahi hai
                if (temp->prev == NULL) {
                    *head_ref = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = NULL;
                    temp = temp->next;
                }
                // agar beech ya end ka node
                else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                    temp = temp->next;
                }

                delete del;
            }
            else {
                temp = temp->next;
            }
        }
    }
};
