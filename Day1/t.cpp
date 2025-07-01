#include <bits/stdc++.h>

#include <cmath>
#include <ostream>
using namespace std;
class Tree
{
   public:
    Tree* left;
    Tree* right;
    int leftrange;
    int rightrange;
    int mid;
    Tree(int val, int lr, int rr)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->leftrange = lr;
        this->rightrange = rr;
        this->mid = (lr + rr) / 2;
    }
    ~Tree()
    {
        // cout << this->val << endl;
        delete this->left;
        delete this->right;
    }
    int get_val()
    {
        return this->val;
    }
    void set_val(int val)
    {
        this->val = val;
        return;
    }

   private:
    int val;
};
int len;
int a[1001];
Tree* ConstructTree(int left, int right)
{
    if (left == right) return new Tree(a[left], left, right);
    Tree* t = new Tree(0, left, right);
    t->left = ConstructTree(left, (left + right) / 2);
    t->right = ConstructTree((left + right) / 2 + 1, right);
    t->set_val(t->left->get_val() + t->right->get_val());
    return t;
}
int GetSum(int l, int r, Tree* root)
{
    if (l == root->leftrange && r == root->rightrange) return root->get_val();
    if (r <= root->mid) return GetSum(l, r, root->left);
    if (l > root->mid) return GetSum(l, r, root->right);
    return GetSum(l, root->mid, root->left) +
           GetSum(root->mid + 1, r, root->right);
}
int main()
{
    cin >> len;
    for (int i = 1; i <= len; i++)
    {
        cin >> a[i];
    }
    Tree* root = ConstructTree(1, len);
    int l, r;
    cin >> l >> r;
    while (l != -1 || r != -1)
    {
        cout << GetSum(l, r, root) << endl;
        cin >> l >> r;
    }
    delete root;
    return 0;
}
