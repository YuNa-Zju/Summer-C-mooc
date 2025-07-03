#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int nums[MAXN];
int dq_arr[MAXN];
int head = 0;
int tail = 0;
int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < k; ++i)
    {
        while (head != tail && nums[i] >= nums[dq_arr[tail - 1]])
        {
            tail--;
        }
        dq_arr[tail++] = i;
    }
    for (int i = k; i < n; ++i)
    {
        printf("%d ", nums[dq_arr[head]]);
        while (head != tail && dq_arr[head] <= i - k)
        {
            head++;
        }

        while (head != tail && nums[i] >= nums[dq_arr[tail - 1]])
        {
            tail--;
        }
        dq_arr[tail++] = i;
    }
    printf("%d\n", nums[dq_arr[head]]);
    return 0;
}
