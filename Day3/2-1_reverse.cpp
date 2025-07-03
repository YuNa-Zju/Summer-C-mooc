#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
void K_Reverse(List L, int K)
{
    if (L == NULL || L->Next == NULL || K <= 1)
    {
        return;
    }

    PtrToNode cur = L->Next;
    PtrToNode pre = L;

    while (cur != NULL)
    {
        PtrToNode head = cur;
        PtrToNode tail = cur;
        int count = 1;

        while (count < K && tail->Next != NULL)
        {
            tail = tail->Next;
            count++;
        }

        if (count < K)
        {
            break;
        }

        PtrToNode nxt = tail->Next;
        tail->Next = NULL;

        PtrToNode prev = NULL;
        PtrToNode curr = head;
        while (curr != NULL)
        {
            PtrToNode next = curr->Next;
            curr->Next = prev;
            prev = curr;
            curr = next;
        }

        pre->Next = prev;
        head->Next = nxt;
        pre = head;
        cur = nxt;
    }
}
