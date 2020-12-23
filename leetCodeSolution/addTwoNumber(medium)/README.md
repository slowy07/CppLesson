## add two sum
**solution 1**
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode dummy, *tail = &dummy;
        while (a || b || carry) {
            if (a) {
                carry += a->val;
                a = a->next;
            }
            if (b) {
                carry += b->val;
                b = b->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return dummy.next;
    }
};
```
