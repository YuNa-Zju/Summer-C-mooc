// 采用二分结合贪心算法
// 时间可能的区间：[max, sum], max是所有时间的最大值，sum是所有时间的总和，
// 用贪心检查二分答案的可能性
#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001];
long long max_ = 0, sum = 0, num = 0;
int check(long long time)
{
    long long num = 1, sum_time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum_time + a[i] > time)
        {
            num++;
            sum_time = a[i];
        }
        else
        {
            sum_time += a[i];
        }
    }
    return num <= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (max_ < a[i]) max_ = a[i];
        sum += a[i];
    }
    long long left = max_, right = sum, mid;
    // cout << check(14) << endl;
    while (left < right)
    {
        mid = (left + right) / 2;
        // cout << left << " " << right << " " << mid << " " << check(mid) <<
        // endl;
        if (check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << right << endl;
    return 0;
}
