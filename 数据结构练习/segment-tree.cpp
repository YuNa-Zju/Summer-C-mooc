#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int l, r;
    ll tag, val;
    Node *left = 0, *right = 0;
    Node(int l, int r, ll val, Node* left, Node* right)
    {
        this->l = l;
        this->r = r;
        this->val = val;
        this->tag = 0;
        this->left = left;
        this->right = right;
    }
    void pushdown()
    {
        if (this->left)
        {
            this->left->val += (this->left->r - this->left->l + 1) * this->tag;
            this->left->tag += this->tag;
        }
        if (this->right)
        {
            this->right->val +=
                (this->right->r - this->right->l + 1) * this->tag;
            this->right->tag += this->tag;
        }
        this->tag = 0;
        return;
    }
};
ll a[100001];
Node* Build(int l, int r)
{
    if (l == r)
    {
        return new Node(l, r, a[l], NULL, NULL);
    }
    int m = (l + r) >> 1;
    Node* left = Build(l, m);
    Node* right = Build(m + 1, r);
    return new Node(l, r, left->val + right->val, left, right);
}
ll Sum(int l, int r, Node* root)
{
    if (l == root->l && r == root->r) return root->val;
    root->pushdown();
    int m = (root->l + root->r) >> 1;
    if (r <= m) return Sum(l, r, root->left);
    if (l >= m + 1) return Sum(l, r, root->right);
    return Sum(l, m, root->left) + Sum(m + 1, r, root->right);
}
void Modify(int l, int r, ll val, Node* root)
{
    if (l == root->l && r == root->r)
    {
        root->tag += val;
        root->val += (r - l + 1) * val;
        return;
    }
    root->pushdown();
    int m = (root->l + root->r) >> 1;
    if (r <= m)
        Modify(l, r, val, root->left);
    else if (l >= m + 1)
        Modify(l, r, val, root->right);
    else
    {
        Modify(l, m, val, root->left);
        Modify(m + 1, r, val, root->right);
    }
    root->val = root->left->val + root->right->val;
}
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Node* root = Build(1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            Modify(x, y, k, root);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << Sum(x, y, root) << endl;
        }
    }
    return 0;
}
