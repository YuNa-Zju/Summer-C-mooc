#include <bits/stdc++.h>

#include <cstdio>
using namespace std;
long long fastpow(long long a, long long b, long long p)
{
    long long res = 1;
    a = a % p;
    while (b)
    {
        if (b % 2 == 1) res = res * a % p;
        a = a * a % p;
        b /= 2;
    }
    return res;
}
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld", a, b, p, fastpow(a, b, p));
    return 0;
}
