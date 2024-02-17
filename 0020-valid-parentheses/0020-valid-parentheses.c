bool isValid(char *s)
{
    char stack[10000];
    int top = -1;

    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
            stack[++top] = *s; // push the left parentheses to the stack, and top++
        else if (*s == ')')
        {
            // if the stack is empty or the top element is not the corresponding left parentheses, return false
            if (top == -1 || stack[top] != '(')
                return false;
            else
                top--; // pop the top element
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