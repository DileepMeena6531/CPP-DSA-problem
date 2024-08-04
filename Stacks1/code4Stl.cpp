#include <iostream>
#include <stack>
using namespace std;

void pushValueBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int topVal = s.top();
    s.pop();
    pushValueBottom(s, val);
    s.push(topVal);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topVal = s.top();
    s.pop();
    reverseStack(s);
    pushValueBottom(s, topVal);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    // pushValueBottom(s,5);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}