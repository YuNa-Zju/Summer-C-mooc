// TODO: 使用dfs改写n皇后
#include <stdio.h>

#include <cstring>

void Print(int *s, int n);
void Queens(int n);
int check(int *s, int n);
int main(void)
{
    int n;

    scanf("%d", &n);
    int s[6] = {5, 3, 1, 0, 0};
    // Queens(n);
    printf("%d", check(s, n));
    return 0;
}
void Print(int *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", s[i]);
    }
}
int check(int *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == 0) continue;
            if (s[i] == s[j]) return 0;
            if ((s[i] + (j - i) + n) % n == s[j] ||
                (s[i] + (i - j) + n) % n == s[j])
                return 0;
        }
    }
    return 1;
}
int queue[50];
void Queen(int n)
{
}
