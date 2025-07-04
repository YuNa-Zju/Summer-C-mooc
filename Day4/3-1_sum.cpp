#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *l, *r;
};
struct node* find(int data, struct node* root)
{
    if (root->data == data) return root;
    if (!root->l && !root->r) return 0;
    if (root->l)
    {
        if (find(data, root->l) != 0) return find(data, root->l);
    }
    if (root->r)
    {
        if (find(data, root->r) != 0) return find(data, root->r);
    }
    return 0;
}
int sum(struct node* root)
{
    if (!root->l && !root->r)
    {
        return root->data;
    }
    return (root->l ? sum(root->l) : 0) + (root->r ? sum(root->r) : 0);
}
int main()
{
    int N, k, r, d, e;
    struct node* root = new node();
    cin >> N >> k;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }  // N可能为0
    root->data = k;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> r >> d >> e;
        struct node* node_ = find(r, root);
        if (d == 0)
        {
            node_->l = new node();
            node_->l->data = e;
        }
        else
        {
            node_->r = new node();
            node_->r->data = e;
        }
    }
    cout << sum(root) << endl;
    return 0;
}
