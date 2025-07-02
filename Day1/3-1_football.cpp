#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int win[1001], score[1001], sum[1001];
int order[1001];
int T, n, a, b, p, q;
int cmp(int a, int b)
{
    if (score[a] > score[b])
    {
        return 1;
    }
    else if (score[a] < score[b])
    {
        return 0;
    }
    if (win[a] > win[b])
    {
        return 1;
    }
    else if (win[a] < win[b])
    {
        return 0;
    }
    if (sum[a] > sum[b])
    {
        return 1;
    }
    else if (sum[a] < sum[b])
    {
        return 0;
    }
    return a < b;
}
int main()
{
    cin >> T;
    for (int _ = 1; _ <= T; _++)
    {
        cin >> n;
        memset(win, 0, sizeof(win));
        memset(score, 0, sizeof(score));
        memset(order, 0, sizeof(order));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            order[i] = i;
        }
        for (int i = 1; i <= n * (n - 1) / 2; i++)
        {
            cin >> a >> b >> p >> q;
            if (p > q)
            {
                score[a] += 3;
            }
            else if (p == q)
            {
                score[a] += 1;
                score[b] += 1;
            }
            else
            {
                score[b] += 3;
            }
            win[a] += p - q;
            win[b] += q - p;
            sum[a] += p;
            sum[b] += q;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j > i; j--)
            {
                if (cmp(order[j], order[j - 1]))
                {
                    int tmp = order[j];
                    order[j] = order[j - 1];
                    order[j - 1] = tmp;
                }
            }
        }
        cout << order[1];
        for (int i = 2; i <= n; i++)
        {
            cout << " " << order[i];
        }
        cout << endl;
    }
    return 0;
}
