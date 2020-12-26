## swap nodes in pairs (easy)

**solution 1**

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode newHead(0), *newTail = &newHead;
        while (head && head->next) {
            ListNode *p = head, *q = head->next;
            head = q->next;
            newTail->next = q;
            q->next = p;
            newTail = p;
        }
        newTail->next = head;
        return newHead.next;
    }
};
```
