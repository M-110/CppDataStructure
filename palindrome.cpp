#include <ostream>
#include <deque>

using namespace std;

bool IsPalindrome(string word)
{
    deque<char> wordDeque;
    
    for(char c : word)
        if (isalpha(c))
            wordDeque.push_back(tolower(c));
        
    while (wordDeque.size() > 1)
    {
        if (wordDeque.front() != wordDeque.back())
            return false;
        
        wordDeque.pop_front();
        wordDeque.pop_back();
    }
    return true;
}

void PalindromeTest(string word)
{
    if (IsPalindrome(word))
        cout << "'" << word << "' is a palindrome" << endl;
    else
        cout << "'" << word << "' is not a palindrome" << endl;
}

void TestPalindromes()
{
    PalindromeTest("Step on no pets");
    PalindromeTest("Mars is great");
    PalindromeTest("Eva, can I see bees in a cave?");
    PalindromeTest("aba");
    PalindromeTest("F");
    PalindromeTest("abbaa");
}
