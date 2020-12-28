class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy, *p = &dummy;
        dummy.next = head;
        for (int i = 1; i < m; ++i) p = p->next;
        auto q = p->next, tail = q;
        for (int i = m; i <= n; ++i) {
            auto node = q;
            q = q->next;
            node->next = p->next;
            p->next = node;
        }
        tail->next = q;
        return dummy.next;
    }
};
