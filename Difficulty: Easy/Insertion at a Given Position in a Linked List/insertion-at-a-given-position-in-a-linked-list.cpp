/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
     if (pos < 1)
        return head;

    // head will change if pos=1
    if (pos == 1) {
        Node *newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    // If position is greater than the 
    // number of nodes
    if (curr == nullptr)
        return head;

    Node *newNode = new Node(val);

    // update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
    }
  
};