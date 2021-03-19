#include <iostream>
#include <stack>
#include <string>
using namespace std;

string divideBy2(int decimal)
{
    stack<int> remainderStack;

    while (decimal > 0)
    {
        int remainder = decimal%2;
        remainderStack.push(remainder);
        decimal = decimal/2;
    }
    string output;
    while (!remainderStack.empty())
    {
        output +=  to_string(remainderStack.top());
        remainderStack.pop();
    }
    return output;
}

string baseConverter(int decimal, int base)
{
    string digits [] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    stack<string> remainderStack;
    while (decimal > 0)
    {
        remainderStack.push(digits[decimal%base]);
        decimal /= base;
    }
    string output;
    while (!remainderStack.empty())
    {
        output +=  remainderStack.top();
        remainderStack.pop();
    }
    return output;
}

void test_binary()
{
    cout << divideBy2(23) << " = 10111" << endl;
    cout << "6423453 to base 16: " << baseConverter(6423453 , 16) << " = 62039D" <<endl;
}
