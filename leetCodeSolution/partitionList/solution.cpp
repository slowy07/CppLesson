class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead, geHead, *ltTail = &ltHead, *geTail = &geHead;
        while (head) {
            auto p = head;
            head = head->next;
            if (p->val < x) {
                ltTail->next = p;
                ltTail = p;
            } else {
                geTail->next = p;
                geTail = p;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = NULL;
        return ltHead.next;
    }
};
