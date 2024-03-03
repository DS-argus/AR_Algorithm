struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 동적 메모리 할당을 사용하여 dummy 노드를 생성합니다.
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *slow = dummy, *fast = dummy;

    // fast 포인터를 n+1 노드 앞으로 이동시킵니다.
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // fast가 리스트의 끝에 도달할 때까지 slow와 fast를 한 칸씩 이동시킵니다.
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow가 제거할 노드의 이전 노드를 가리키므로, slow의 next를 변경합니다.
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;

    // toDelete가 가리키는 노드를 메모리에서 해제합니다.
    free(toDelete);

    struct ListNode* newHead = dummy->next;
    // dummy 노드를 메모리에서 해제합니다.
    free(dummy);
    
    return newHead;
}