## convert sort list to binary search tree (medium)

**solution 1**
```cpp
class Solution {
private:
  int getLen(ListNode *head) {
    int len = 0;
    for (; head; head = head->next, ++len);
    return len;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    int len = getLen(head);
    ListNode *node = head, *prev = NULL;
    for (int n = len / 2; n; --n) {
      prev = node;
      node = node->next;
    }
    TreeNode *root = new TreeNode(node->val);
    if (prev) {
      prev->next = NULL;
      root->left = sortedListToBST(head);
    }
    root->right = sortedListToBST(node->next);
    return root;
  }
};
```
**solution 2**
```cpp
class Solution {
private:
  TreeNode *build(ListNode *head, ListNode *end) {
    if (head == end) return NULL;
    auto slow = head, fast = head;
    while (fast != end && fast->next != end) {
      fast = fast->next->next;
      slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = build(head, slow);
    root->right = build(slow->next, end);
    return root;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    return build(head, NULL);
  }
};
```
