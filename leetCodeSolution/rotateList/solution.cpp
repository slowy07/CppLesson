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
