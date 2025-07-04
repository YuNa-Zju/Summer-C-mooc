#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int dp[110][110];
char a[110], b[110];
// 动态规划：dp[i][j]代表a的前i个字母和b前j个字母组成的最长公共子串长度
// 那么如果a[i] = b[j] dp[i + 1][j + 1] = dp[i][j] + 1
// 如果不相等，那么dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])
// （要么a匹配不上，要么b匹配不上）
int main()
{
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < lena; i++)
    {
        for (int j = 0; j < lenb; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    // Print array 'dp'
    //  for (int i = 0; i < lena; i++)
    //  {
    //      for (int j = 0; j < lenb; j++)
    //      {
    //          cout << dp[i][j] << " ";
    //      }
    //      cout << endl;
    //  }
    cout << dp[lena][lenb] << endl;
    return 0;
}
