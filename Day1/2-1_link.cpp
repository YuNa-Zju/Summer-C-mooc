#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    struct ListNode* next = 0;
};
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* less = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* more = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    struct ListNode *less_t = less, *more_t = more;
    while (cur)
    {
        if (cur->data >= x)
        {
            more_t->next = cur;
            more_t = cur;
        }
        else
        {
            less_t->next = cur;
            less_t = cur;
        }
        cur = cur->next;
    }
    less_t->next = more->next;
    head = less->next;
    return head;
}
