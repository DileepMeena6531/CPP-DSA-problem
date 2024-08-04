#include <iostream>
#include <stack>
using namespace std;

// time complexity O(N)
bool isDuplicate(string str)
{
    stack<int> s;

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] != ')')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.top() == '(')
            {
                return true;
            }

            while (s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main()
{
    string str = "(a+b)";

    if (isDuplicate(str))
    {
        cout << "duplicate";
    }
    else
    {
        cout << "no duplicate";
    }

    return 0;
}