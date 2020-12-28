## populating next right pointers in each node 2 (medium)

**solution 1 DFS**
```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node head, *tail = &head;
        for (auto node = root; node; node = node->next) {
            if (node->left) {
                tail->next = node->left;
                tail = tail->next;
            }
            if (node->right) {
                tail->next = node->right;
                tail = tail->next;
            }
        }
        connect(head.next);
        return root;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        auto first = root;
        while (first) {
            Node head, *tail = &head;
            for (auto node = first; node; node = node->next) {
                if (node->left) {
                    tail->next = node->left;
                    tail = tail->next;
                }
                if (node->right) {
                    tail->next = node->right;
                    tail = tail->next;
                }
            }
            first = head.next;
        }
        return root;
    }
};
```
