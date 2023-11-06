bool isValid(char *s)
{
    char stack[10000];
    int top = -1;

    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
            stack[++top] = *s;
        else if (*s == ')')
        {
            if (top == -1 || stack[top] != '(')
                return false;
            else
                top--;
        }
        else if (*s == ']')
        {
            if (top == -1 || stack[top] != '[')
                return false;
            else
                top--;
        }
        else if (*s == '}')
        {
            if (top == -1 || stack[top] != '{')
                return false;
            else
                top--;
        }

        s++;
    }

    if (top != -1)
        return false;
    else
        return true;
}