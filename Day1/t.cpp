#include <bits/stdc++.h>

#include <cmath>
using namespace std;
class Tree
{
   public:
    Tree* left;
    Tree* right;
    Tree(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
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
int main()
{
    int n;
    cin >> n;
    int len = pow(2, n);
    int a[len + 1];
    for (int i = 1; i <= len; i++)
    {
        cin >> a[i];
    }
    return 0;
}
