## rotation list (medium)

**solution 1**
```cpp
class Solution {
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, ++len);
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;
        auto p = head, q = head;
        while (k--) q = q->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        auto h = p->next;
        q->next = head;
        p->next = NULL;
        return h;
    }
};
```
**solution 2**
```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = 1;
        auto p = head;
        for (; p->next; ++len, p = p->next);
        p->next = head;
        k = len - k % len;
        while (k--) p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
```
