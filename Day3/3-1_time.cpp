#include <stdio.h>
int n, cur = 0, s[10005], f[10005], order[10005], cnt = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        order[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            if (f[order[j]] < f[order[j - 1]])
            {
                int tmp = order[j];
                order[j] = order[j - 1];
                order[j - 1] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[order[i]] >= cur)
        {
            cnt++;
            cur = f[order[i]];
        }
    }
    printf("%d", cnt);
    return 0;
}
// TODO: 效率不够高，需要使用快速排序或者归并排序
