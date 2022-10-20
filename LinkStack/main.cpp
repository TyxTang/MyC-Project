#include <cstring>
#include "LinkStack.h"

bool Math(char* str)
{
    LinkStack<char>st1;
    char e;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
            st1.Push(str[i]);
        else if (str[i] == ')')
        {
            if (st1.Empty())
                return false;
            else
                st1.Pop(e);
        }
    }
    if (st1.Empty())
        return true;
    else
        return false;
}
int main()
{
    char s[50];
    cout << "请输入表达式："<<endl;
    cin >> s;
    if (Math(s))
        cout << "括号匹配！" << endl;
    else
        cout << "括号不匹配！" << endl;
    return 0;
}

