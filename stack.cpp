#include <iostream>
#include <stack>

using namespace std;

void basic_stack()
{
    stack<int> newStack;

    newStack.push(5);
    newStack.push(44);
    newStack.push(34);

    cout << "Is stack empty? " << newStack.empty() << endl;

    cout << "Stack Size? " << newStack.size() << endl;

    cout << "Top Element? " << newStack.top() << endl;

    cout << "Popping last element..." << endl;

    newStack.pop();

    cout << "New top element? " << newStack.top() << endl;

    cout << "New Size? " << newStack.size() << endl;
}

void balance_check(string symbolString)
{
    stack<string> s;
    bool balanced = true;
    int index = 0;
    int str_len = symbolString.length();

    while (index < str_len && balanced)
    {
        string symbol;
        symbol = symbolString[index];
        if (symbol == "(")
            s.push(symbol);
        else if (symbol == ")")
            if (s.empty())
                balanced = false;
            else
                s.pop();
        index++;
    }
    cout << symbolString << " balanced? " << (balanced && s.empty()) << endl;

}

bool inString(string symbol, string symbols)
{
    return symbols.find(symbol) != string::npos;
}

bool matches (string open, string close)
{
    string opens = "({[";
    string closes = ")]}";
    return inString(open, opens) == inString(close, closes);
}

void multi_balance_check(string symbolString)
{
    stack<string> s;
    bool balanced = true;
    int index = 0;
    int stringLength = symbolString.length();

    while (index < stringLength && balanced)
    {
        string symbol;
        symbol = symbolString[index];
        string opens = "({[";
        string closes = ")]}";
        if (inString(symbol, opens))
            s.push(symbol);
        else if (inString(symbol, closes))
        {
            if (s.empty())
                balanced = false;
            else
            {
                string top = s.top();
                s.pop();
                if (!matches(top, symbol))
                {
                    balanced = false;
                    break;
                }
            }
        }
        index++;
    }
    cout << symbolString << "multi-balanced? " << (balanced && s.empty()) << endl;
}

void test_stack()
{
    basic_stack();
    balance_check("(())");
    balance_check("()()())");
    balance_check("(((()))(");
    multi_balance_check("({[]})");
    multi_balance_check("({[)}");
}