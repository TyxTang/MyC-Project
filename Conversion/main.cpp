#include "SqStack.h"

void Conversion(int n)
{
    SqStack<int>st1(32);
    int e;
    if (n > 0)
    {
        while (n != 0)
        {
            e = n % 2;
            st1.Push(e);
            n = n / 2;
        }
        while (!st1.Empty())
        {
            st1.Pop(e);
            cout << e;
        }
    }
    else if (n == 0)
        cout << 0;
    else
        cout << "参数错误!";
    cout << endl;
}
int main()
{
    int n;
    cout << "输入一个非负十进制数："<<endl;
    cin >> n;
    Conversion(n);
    return 0;
}
