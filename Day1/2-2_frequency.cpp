#include <bits/stdc++.h>

#include <cstring>
using namespace std;
int frequency(char* paragraph, char* from, char* to);
int main()
{
    int N;
    char* s;
    int from, to;
    int freq;
    scanf("%d\n", &N);
    s = (char*)malloc((N + 1) * sizeof(char));
    cin.getline(s, N);
    scanf("%d %d", &from, &to);

    freq = frequency(s, s + from - 1, s + to - 1);

    printf("%d\n", freq);
    return 0;
}
int frequency(char* paragraph, char* from, char* to)
{
    // cout << *from << *to << endl;
    int cnt = 0, len = strlen(paragraph);
    int flag = 1;
    for (int i = 0; i < len; i++)
    {
        flag = 1;
        if (paragraph[i] == *from)
        {
            int t = i;
            for (char* j = from; j <= to; j++)
            {
                // cout << *j << endl;
                if (*j == paragraph[t] && t < len)
                {
                    t++;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
