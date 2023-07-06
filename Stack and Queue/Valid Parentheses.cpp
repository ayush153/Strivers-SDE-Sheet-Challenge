int pop(stack<char>& stack) 
{
    int c = stack.top();
    stack.pop();
    return c;
}

bool isValidParenthesis(string expression)
{
    // Write your code here.
     stack<char> stack;

    for (char c : expression)
    {
        if (c == '(')  stack.push(')');
        
        else if (c == '{')   stack.push('}');
        
        else if (c == '[')   stack.push(']');
        
        else if (stack.empty() || pop(stack) != c) return false;
        
    }
    return stack.empty();
}
