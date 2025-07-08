#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int q[100001], head = 0, tail = 0;
int num[100001];
void append(int a)
{
    while (head != tail)
    {
        if (q[tail - 1] < a) tail--;
        if (q[tail - 1] >= a)
        {
            q[tail++] = a;
            return;
        }
    }
    if (head == tail)
    {
        q[tail++] = a;
        return;
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= k; i++)
    {
        append(num[i]);
    }
    cout << q[head];
    for (int i = k + 1; i <= n; i++)
    {
        if (q[head] == num[i - k]) head++;
        append(num[i]);
        cout << " " << q[head];
        // cout << "q: ";
        // for (int j = head; j < tail; j++)
        // {
        //     cout << q[j] << " ";
        // }
        // cout << endl;
    }
    return 0;
}
