#include <bits/stdc++.h>
using namespace std;
int num[10001];
char ops[10001];
int num_h = 0, op_h = 0;
char s[10001];
map<char, int> priority;

int is_digit(char x)
{
    return '0' <= x && x <= '9';
}

int is_op(char x)
{
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '^';
}

int is_right(char x)
{
    return x == '^';
}

void calc()
{
    int r = num[--num_h], l;
    if (!num_h)
        l = 0;
    else
        l = num[--num_h];
    char op = ops[--op_h];
    int res;
    if (op == '+')
    {
        res = l + r;
    }
    else if (op == '-')
    {
        res = l - r;
    }
    else if (op == '*')
    {
        res = l * r;
    }
    else if (op == '/')
    {
        res = l / r;
    }
    else if (op == '%')
    {
        res = l % r;
    }
    else if (op == '^')
    {
        res = 1;
        while (r > 0)
        {
            if (r % 2 == 1) res *= l;
            l *= l;
            r /= 2;
        }
    }
    num[num_h++] = res;
}

int calculate(char* s)
{
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['%'] = 2;
    priority['^'] = 3;
    num_h = 0;
    op_h = 0;
    int pre = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (is_digit(s[i]))
        {
            int val = s[i] - '0';
            while (i < strlen(s) && is_digit(s[++i]))
            {
                val = val * 10 + s[i] - '0';
            }
            num[num_h++] = val;
            pre = 0;
        }
        if (is_op(s[i]))
        {
            if (pre && s[i] == '-')
            {
                num[num_h++] = 0;
            }
            while (op_h != 0 && ((ops[op_h - 1] != '(' && !is_right(s[i]) &&
                                  priority[ops[op_h - 1]] >= priority[s[i]])) ||
                   (is_right(s[i]) && priority[ops[op_h - 1]] > priority[s[i]]))
            {
                calc();
            }
            ops[op_h++] = s[i];
            pre = 0;
        }
        if (s[i] == '(')
        {
            ops[op_h++] = '(';
            pre = 1;
        }
        if (s[i] == ')')
        {
            while (ops[op_h - 1] != '(')
            {
                calc();
            }
            op_h--;
            pre = 0;
        }
    }
    while (op_h != 0)
    {
        calc();
    }
    return num[0];
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        cin.getline(s, sizeof(s));
        cout << calculate(s) << endl;
    }
    if (argc == 2)
    {
        cout << calculate(argv[1]) << endl;
    }
    return 0;
}
