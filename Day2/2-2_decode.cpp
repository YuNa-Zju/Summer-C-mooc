#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
using namespace std;
#define N 100
#define M 5
int decode(char **s);
int main()
{
    char *s[M];
    int i;
    int key;
    for (i = 0; i < M; i++)
    {
        s[i] = (char *)malloc((N + 1) * sizeof(char));
        cin.getline(s[i], N);
    }

    key = decode(s);
    printf("%04d", key);
    for (i = 0; i < M; i++)
    {
        free(s[i]);
    }

    return 0;
}
int decode(char **s)
{
    int ans = 0, cnt = 0, len;
    int len_end = strlen(s[M - 1]);
    for (int i = 0; i <= M - 2; i++)
    {
        len = strlen(s[i]);
        // cout << len << endl;
        cnt = 0;
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len_end; k++)
            {
                if (s[M - 1][k] == s[i][j])
                {
                    cnt++;
                    break;
                }
            }
        }
        // cout << cnt << endl;
        ans = ans * 10 + cnt;
    }
    return ans;
}
