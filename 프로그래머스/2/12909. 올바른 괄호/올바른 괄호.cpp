#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    if(s[0] == ')' || s.size()%2==1 || s[s.size()-1] == '(')
        return false;
    
    stack<char> MyStack;
    
    for(char c : s)
    {
        if(c == '(')
        {
            MyStack.push('(');
        }
        else if(c == ')')
        {
            if(MyStack.top() == '(')
            {
                MyStack.pop();
            }
            else
            {
                MyStack.push(')');
            }
        }
    }
    
    if(MyStack.empty())
        return true;

    return false;
}