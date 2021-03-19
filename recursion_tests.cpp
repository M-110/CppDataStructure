#include <iostream>
#include <vector>
#include <string>
using namespace std;


int SumVector(vector<int> numVector)
{
    if (numVector.size() <= 1)
        return numVector[0];
    else
        return numVector[0] + SumVector(
                vector<int>(numVector.begin() + 1, numVector.begin() + numVector.size()));
}

string ConvertToBase(int num, int base)
{
    string conversionTable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (num < base)
        return  string(1, conversionTable[num]);
    else
        return ConvertToBase(num/base, base) + conversionTable[num%base];
}

void TestRecursion()
{   
    vector<int> myVector{5, 10, 12, 15, 14};
    vector<int> theVector{myVector.begin(), myVector.end()};
    cout << "Sum of vectors <50, 10-12, 12, 15, 14>: " << SumVector(theVector) << endl;
    
    cout << "Converting 143 to binary: " << ConvertToBase(143, 2) << endl;
    cout << "Converting 143 to hexadecimal: " << ConvertToBase(143, 16) << endl;
}