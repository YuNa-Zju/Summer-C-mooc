#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int parent[200005];
int r[200005];
int f(int x)
{
    if (x != parent[x])
    {
        x = f(parent[x]);
    }
    return x;
}
void u(int a, int b)
{
    a = f(a);
    b = f(b);
    if (a == b)
    {
        return;
    }
    if (r[a] < r[b]) parent[a] = b;
    if (r[a] > r[b]) parent[b] = a;
    if (r[a] == r[b])
    {
        parent[a] = b;
        r[b]++;
    }
    return;
}
int quest(int a, int b)
{
    return f(a) == f(b);
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    memset(r, 1, sizeof(r));
    for (int _ = 1; _ <= M; _++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
        {
            u(x, y);
        }
        if (z == 2)
        {
            if (quest(x, y))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}
