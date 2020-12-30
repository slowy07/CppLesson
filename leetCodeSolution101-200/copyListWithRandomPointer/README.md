## copy list with random pointer (medium)

**solution 1 unordered map**
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> old_to_new;
        Node* new_head = new Node(head->val);
        Node *new_curr = new_head, *curr = head->next;
        old_to_new[head] = new_head;
        while (curr) {
            new_curr->next = new Node(curr->val);
            new_curr = new_curr->next;
            old_to_new[curr] = new_curr;
            curr = curr->next;
        }
        new_curr = new_head;
        curr = head;
        while (curr) {
            new_curr->random = old_to_new[curr->random];
            curr = curr->next;
            new_curr = new_curr->next;
        }
        return new_head;
    }
};
```
