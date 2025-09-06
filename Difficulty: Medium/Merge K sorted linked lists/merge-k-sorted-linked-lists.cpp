/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // map will store elements in sorted order
        map<int, int> mp;  

        // Step 1: Traverse all linked lists
        for (int i = 0; i < arr.size(); i++) {
            Node* head = arr[i];  // head of current list
            while (head != NULL) {
                mp[head->data]++;  // count frequency
                head = head->next; // move ahead
            }
        }

        // Step 2: Build final linked list
        Node dummy(0);
        Node* curr = &dummy;

        for (auto& it : mp) {
            int value = it.first;
            int freq = it.second;

            // insert `freq` copies of value
            while (freq--) {
                curr->next = new Node(value);
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
