/*
 ����: Annie Kim, anniekim.pku[at]gmail.com
 ʱ��: Sep 18, 2013
 ��Ŀ: ���ƴ����ָ�������
 �Ѷ�: Hard
 ����: http://www.itint5.com/oj/#19
 ����: 
 ����һ��������������˰���nextָ���⣬������һ��randomָ�룬��ָ��ָ��������ĳ����㡣
 �븴������һ���µ�����randomָ����Ҫָ���������ж�Ӧ�Ľ�㡣
 ����ԭ����ĳ�����randomָ��ָ���2����㣬��ô�½���randomָ��ҲҪָ��������ĵ�2����㡣

 ��ʾ��������ڿռ临�Ӷ�O(1)���㷨������Ҫʹ���κζ��⸨���ռ䡣�벻Ҫ�ı�ԭ����Ľṹ��

 Solution: ����Ҫʹ���κζ��⸨���ռ䡣��Ҫ�ȴ���ԭ����Ľṹ�������¸�ԭ��
           �������google �����ƴ����ָ����������кܶ��˽��⡣
*/

/**
������Ķ���(�벻Ҫ�ڴ����ж��������)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/

// ���ظ��Ƶ�������ͷ���
ListNode* copyListWithRandomPtr(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next->next) {
        ListNode *node = new ListNode;
        node->next = cur->next;
        cur->next = node;
    }

    for (ListNode *cur = head; cur; cur = cur->next->next)
        cur->next->random = cur->random->next;

    ListNode dummyHead; dummyHead.next = NULL;
    ListNode *newCur = &dummyHead;
    for (ListNode *cur = head; cur; cur = cur->next) {
        newCur->next = cur->next;
        newCur = newCur->next;
        cur->next = cur->next->next;
    }

    return dummyHead.next;
}