#include <stdio.h>
#define N 100

int max(int *a, int m, int n);
int min(int *a, int m, int n);
// 注意采用分治法，不使用循环语句

int main()
{
    int i, n, a[N], max_val, min_val;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    max_val = max(a, 0, n - 1);
    min_val = min(a, 0, n - 1);
    printf("max=%d,min=%d", max_val, min_val);
    return 0;
}
int max(int *a, int m, int n)
{
    if (m == n) return a[m];
    return max(a, m, (m + n) / 2) > max(a, (m + n) / 2 + 1, n)
               ? max(a, m, (m + n) / 2)
               : max(a, (m + n) / 2 + 1, n);
}
int min(int *a, int m, int n)
{
    if (m == n) return a[m];
    return min(a, m, (m + n) / 2) < min(a, (m + n) / 2 + 1, n)
               ? min(a, m, (m + n) / 2)
               : min(a, (m + n) / 2 + 1, n);
}
