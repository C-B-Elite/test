#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool stackTest(char str[], size_t size)
{
    stack<char> s;
    for (size_t i = 0; i < size; ++i)
    {
        if (str[i] != '(' && str[i] != ')' &&
            str[i] != '[' && str[i] != ']' &&
            str[i] != '{' && str[i] != '}')
        {
            continue;
        }
        else
        {
            if ('(' == str[i] || '{' == str[i] || '[' == str[i])
            {
                s.push(str[i]);
            }
            else
            {
                if (s.empty())
                {
                    cout << "wrong expression" << endl;
                    return false;
                }
                char c = s.top();
                if (('(' == c && ')' == str[i]) ||
                    ('{' == c && '}' == str[i]) ||
                    ('[' == c && ']' == str[i]))
                {
                    s.pop();
                }
                else
                {
                    cout << "wrong expression" << endl;
                    return false;
                }
            }
        }
    }
    if (!s.empty())
    {
        cout << "wrong expression" << endl;
        return false;
    }
    cout << "right expression" << endl;
    return true;
}

int main()
{
    char a[] = "a+(2+[2+2])";
    char b[] = "a+[2+(2+2)]";
    char c[] = " )(1+2)";
    char d[] = "[8*9+(10+10)";

    cout << stackTest(a, strlen(a)) << endl;
    cout << stackTest(b, strlen(b)) << endl;
    cout << stackTest(c, strlen(c)) << endl;
    cout << stackTest(d, strlen(d)) << endl;
    return 0;
}