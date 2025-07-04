#include <malloc.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *Lson, *Rson;
} Bnode, *Bptr;

void leaf(Bptr p);  // 只需完成此函数

Bptr creat();  // 以扩充先序遍历方式构造二叉树,已构造完成

int main()
{
    Bptr root;
    root = creat();
    leaf(root);
    return 0;
}

void leaf(Bptr p)
{
    if (!p->Lson && !p->Rson)
    {
        printf("%d ", p->data);
        return;
    }
    if (p->Lson) leaf(p->Lson);
    if (p->Rson) leaf(p->Rson);
}
