char pair(char a)
{
    if (a == '}')
        return '{';
    if (a == ']')
        return '[';
    if (a == ')')
        return '(';
    return 0;
}
bool isValid(char *s)
{
    int n = strlen(s);
    if (n % 2 == 1)
        return false;
    else
    {
        int stk[n + 1], top = 0;
        for (int i = 0; i < n; i++)
        {
            char pa = pair(s[i]);
            if (pa)
            {
                if (top == 0 || stk[top - 1] != pa)
                {
                    return false;
                }
                top--;
            }
            else
            {
                stk[top++] = s[i];
            }
        }
        return top == 0;
    }
} /////