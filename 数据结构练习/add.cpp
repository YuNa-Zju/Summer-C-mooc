#include <bits/stdc++.h>

#include <cstdio>
using namespace std;
char a[1001], b[1001];
char c[1001];
void Reverse(char* a, int len)
{
    char t;
    for (int i = 0; i <= len / 2 - 1; i++)
    {
        t = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = t;
    }
    return;
}
int main()
{
    int plus = 0;
    int lena, lenb, lenc;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> a >> b;
    lena = strlen(a);
    lenb = strlen(b);
    lenc = max(lena, lenb);
    // cout << a << b;
    Reverse(a, lena);
    Reverse(b, lenb);
    for (int i = 0; i < lena; i++)
    {
        a[i] -= '0';
    }
    for (int i = 0; i < lenb; i++)
    {
        b[i] -= '0';
    }
    // cout << lenc;
    // cout << a << endl << b << endl;
    for (int i = 0; i < lenc; i++)
    {
        plus += a[i] + b[i];
        c[i] = plus % 10;
        plus /= 10;
    }
    if (plus == 1)
    {
        c[lenc] = plus;
        lenc++;
    }
    Reverse(c, lenc);
    for (int i = 0; i < lenc; i++)
    {
        putchar(c[i] + '0');
    }
    return 0;
}
