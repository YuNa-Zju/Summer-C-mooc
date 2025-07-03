#include <bits/stdc++.h>

#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, m;
    int a[30][30];
    char t;
    int delta[10][10] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int flag[30][30];
    memset(flag, 0, sizeof(flag));
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            t = getchar();
            if (t == '#')
                a[i][j] = 0;
            else if (t == '.')
                a[i][j] = 1;
            else
                a[i][j] = 2;
        }
        getchar();
    }
    for (int _ = 1; _ < m; _++)
    {
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int x = 0; x < 4; x++)
                {
                    int dx = delta[x][0] + i;
                    int dy = delta[x][1] + j;
                    if (dx < 1 || dx > n || dy < 1 || dy > n) continue;
                    if (a[dx][dy] == 0) continue;
                    if (a[i][j] == 2 && a[dx][dy] == 1 && !flag[i][j])
                    {
                        a[dx][dy] = 2;
                        flag[dx][dy] = 1;
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 2) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
