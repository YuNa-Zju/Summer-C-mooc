#include <bits/stdc++.h>
using namespace std;
int q[10005];
int tail = 0;
void up(int t)
{
    if (t == 0) return;
    if (q[t] < q[(t + 1) / 2 - 1])
    {
        int tmp = q[t];
        q[t] = q[(t + 1) / 2 - 1];
        q[((t + 1) / 2) - 1] = tmp;
    }
    up((t + 1) / 2 - 1);
}
void down(int t)
{
    if (t * 2 + 1 >= tail) return;
    if (t * 2 + 2 >= tail)
    {
        if (q[t] > q[t * 2 + 1])
        {
            int tmp = q[t];
            q[t] = q[t * 2 + 1];
            q[t * 2 + 1] = tmp;
        }
        return;
    }
    int min_index = t * 2 + 1;
    if (q[t * 2 + 1] > q[t * 2 + 2]) min_index += 1;
    if (q[t] <= q[min_index])
        return;
    else
    {
        int tmp = q[t];
        q[t] = q[min_index];
        q[min_index] = tmp;
        down(min_index);
    }
}
void insert(int x)
{
    q[tail++] = x;
    up(tail - 1);
}
int del()
{
    int res = q[0];
    q[0] = q[--tail];
    down(0);
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int _ = 1; _ <= n; _++)
    {
        int op, num;
        cin >> op;
        if (op == 1)
        {
            cin >> num;
            insert(num);
            // for (int i = 0; i < tail; i++)
            // {
            //     cout << q[i] << " ";
            // }
            // cout << endl;
        }
        if (op == 2)
        {
            cout << q[0] << endl;
        }
        if (op == 3)
        {
            del();
        }
    }
    return 0;
}
