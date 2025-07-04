#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int cnt = 0, head[10001], ed[10001], nxt[10001];
void add_edge(int a, int b)
{
    cnt++;
    ed[cnt] = b;
    nxt[cnt] = head[a];
    head[a] = cnt;
    return;
}
int dist[10001];
int main()
{
    int n, e, m;
    cin >> n >> e >> m;
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int _ = 1; _ <= m; _++)
    {
        int x, y, queue[10001], qhead = 0, tail = 0;
        int is_visited[10001];
        memset(queue, 0, sizeof(queue));
        memset(is_visited, 0, sizeof(is_visited));
        memset(dist, -1, sizeof(dist));
        cin >> x >> y;
        dist[x] = 0;
        is_visited[x] = 1;
        queue[tail++] = x;
        while (qhead <= tail)
        {
            int cur = queue[qhead++];
            // cout << "dist:";
            // for (int i = 0; i < n; i++) cout << dist[i] << " ";
            // cout << endl;
            for (int p = head[cur]; p != 0; p = nxt[p])
            {
                int v = ed[p];
                if (dist[v] == -1)
                {
                    dist[v] = dist[cur] + 1;
                }
                else
                {
                    dist[v] = min(dist[v], dist[cur] + 1);
                }
                if (!is_visited[v])
                {
                    queue[tail++] = v;
                    is_visited[v] = 1;
                }
            }
        }
        cout << dist[y] << endl;
    }
}
