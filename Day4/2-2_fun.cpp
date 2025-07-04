#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int fun(int *w, int N)
{
    int dp[1000001];
    if (N == 0) return 0;
    if (N == 1) return 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 0;
    }
    dp[0] = w[0];
    dp[1] = w[1];
    for (int i = 2; i < N; i++)
    {
        dp[i] = (dp[i - 2] < dp[i - 1] ? dp[i - 2] : dp[i - 1]) + w[i];
    }
    return dp[N - 2] < dp[N - 1] ? dp[N - 2] : dp[N - 1];
}
int w[101], N;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }
    cout << fun(w, N) << endl;
    return 0;
}
