#include <stdio.h>
int gys(int m, int n);
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", gys(m, n));
    return 0;
}

int gys(int m, int n)
{
    if (n == 0) return m;
    return gys(n, m % n);
}
