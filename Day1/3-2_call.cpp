#include <bits/stdc++.h>
using namespace std;
int n;
char date[101][101];
string call[101], name[101];
int order[101];
int cmp(int a, int b)
{
    int yeara = 0, yearb = 0, montha = 0, monthb = 0, datea = 0, dateb = 0;
    for (int i = 0; i < 4; i++)
    {
        yeara = yeara * 10 + date[a][i] - '0';
        yearb = yearb * 10 + date[b][i] - '0';
    }
    for (int i = 4; i < 6; i++)
    {
        montha = montha * 10 + date[a][i] - '0';
        monthb = monthb * 10 + date[b][i] - '0';
    }
    for (int i = 6; i < 8; i++)
    {
        datea = datea * 10 + date[a][i] - '0';
        dateb = dateb * 10 + date[b][i] - '0';
    }
    // cout << yeara << " " << montha << " " << datea << endl;
    if (yeara != yearb)
    {
        return yeara < yearb;
    }
    if (montha != monthb)
    {
        return montha < monthb;
    }
    return datea < dateb;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> name[i] >> date[i] >> call[i];
        order[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            if (cmp(order[j], order[j - 1]))
            {
                int tmp = order[j];
                order[j] = order[j - 1];
                order[j - 1] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << name[order[i]] << " " << date[order[i]] << " " << call[order[i]]
             << endl;
    }
}
