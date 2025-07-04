#include <bits/stdc++.h>
using namespace std;
int N, V, s[10005], v[10005], w[10005];
int dp[10005];
int main()
{
    int ans = 0;
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        int n = 0;
        int v_, w_, s_;
        cin >> v_ >> w_ >> s_;
        for (int j = 1; j <= s_; j++)
        {
            v[++n] = v_ * j;
            w[n] = w_ * j;
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = V; k >= v[j]; k--)
            {
                dp[k] = max(dp[k], dp[k - v[j]] + w[j]);
                if (ans < dp[k]) ans = dp[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
