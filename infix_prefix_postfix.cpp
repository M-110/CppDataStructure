#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string convert_to_postfix(const string& expression)
{
    stack<char> operatorStack;
    string output;
    string operators = "+/-*";

    for (const char& token : expression)
    {
        if (token == ' ')
            continue;
        else if (token == '(')
            operatorStack.push(token);
        else if (token == ')')
        {
            while(operatorStack.top() != '(')
            {
                output += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (operators.find(token) != string::npos)
        {
            if (token == '+' or token == '-')
                while(!operatorStack.empty() and (operatorStack.top() == '*' or operatorStack.top() == '/'))
                {
                    output += operatorStack.top();
                    operatorStack.pop();
                }
            operatorStack.push(token);
        }
        else
            output += token;
    }
    while (!operatorStack.empty())
    {
        output += operatorStack.top();
        operatorStack.pop();
    }
    return output;
}

void test_in_pre_post_fix()
{
    cout << "postfix conversion: ((A*B)+(C*D)) --> " << convert_to_postfix("((A*B)+(C*D))") << endl;
    cout << "postfix conversion: ( A + B ) * C - ( D - E ) * ( F + G ) --> " << convert_to_postfix("( A + B ) * C - ( D - E ) * ( F + G )") << endl;
}