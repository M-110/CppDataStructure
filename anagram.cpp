#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2)
{
    int count = 0;

    for (char c : s1)
    {
        bool matched = false;
        for (char v : s2)
        {
            count++;
            if (c == v)
                matched = true;
        }
        if (!matched)
            return false;
    }

    cout << "1: Solved in " << count << endl;
    return true;
}

bool isAnagram2(string s1, string s2)
{
    int count = 0;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    bool matched = true;

    for (int i = 0; i < s1.length() && matched; i++)
    {
        count++;
        matched = s1[i] == s2[i];
    }
    cout << "2: Solved in " << count << " + n^2 for sorting" << endl;
    return matched;
}



bool isAnagram3(string s1, string s2)
{
    int count = 0;
    bool matched = true;
    int c1[26] = {0};
    int c2[26] = {0};

    for (char c : s1)
    {
        count++;
        c1[(int)c-97]++;
    }


    for (char c : s2)
    {
        count++;
        c2[(int)c-97]++;
    }


    for (int i = 0; i < 26 && matched; i++)
    {
        count++;
        if (c1[i] != c2[i])
            matched = false;
    }

    cout << "3: Solved in " << count << endl;
    return matched;
}

void test_anagram()
{
    cout << "True: " << isAnagram("python", "typhon") << endl;

    cout << "False: " << isAnagram("python", "pythom") << endl;

    cout << "True: " << isAnagram2("python", "typhon") << endl;

    cout << "False: " << isAnagram2("python", "pythom") << endl;

    cout << "True: " << isAnagram3("python", "typhon") << endl;

    cout << "False: " << isAnagram3("python", "pythom") << endl;


    string s1 = "abbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddgggggggggggggggggggggggggggggggggggggggggggggggggggggtttttttttttttttttttttttttttttttttttttttttttxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxabbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddgggggggggggggggggggggggggggggggggggggggggggggggggggggtttttttttttttttttttttttttttttttttttttttttttxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxabbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddgggggggggggggggggggggggggggggggggggggggggggggggggggggtttttttttttttttttttttttttttttttttttttttttttxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxabbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddgggggggggggggggggggggggggggggggggggggggggggggggggggggtttttttttttttttttttttttttttttttttttttttttttxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxabbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddgggggggggggggggggggggggggggggggggggggggggggggggggggggtttttttttttttttttttttttttttttttttttttttttttxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    string s2 = s1;
    cout << "Testing using an anagram of length " << s1.length() << endl;
    isAnagram(s1, s2);
    isAnagram2(s1, s2);
    isAnagram3(s1, s2);
}