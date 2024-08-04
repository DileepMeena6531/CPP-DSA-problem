#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// O(n) time complexity
bool validParandicis(string arr)
{
    stack<char> s;

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            s.push(arr[i]);
        }
        else
        {
            if(s.empty()){
                return false;
            }
            else if(arr[i] == ']' and s.top() == '[' || arr[i] == ')' and s.top() == '(' || arr[i] == '}' and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{

    string arr = "[({})]";

    if (validParandicis(arr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}