#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Vector summation
int SumVector(vector<int> numVector)
{
    if (numVector.size() <= 1)
        return numVector[0];
    else
        return numVector[0] + SumVector(
                vector<int>(numVector.begin() + 1, numVector.begin() + numVector.size()));
}

// Binary converter
string ConvertToBase(int num, int base)
{
    string conversionTable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (num < base)
        return  string(1, conversionTable[num]);
    else
        return ConvertToBase(num/base, base) + conversionTable[num%base];
}

// Towers Section
string MoveRing(char fromTower, char toTower)
{
    string movement;
    movement.push_back(fromTower);
    movement += " to ";
    movement.push_back(toTower);
    movement += ", ";
    return movement;
}

string MoveTower(int height, char fromTower, char toTower, char withTower)
{
    if (height < 1) return "";
    return MoveTower(height - 1, fromTower, withTower, toTower) +
            MoveRing(fromTower, toTower) +
            MoveTower(height - 1, withTower, toTower, fromTower);
}

void TowersOfHanoi(int numberOfRings)
{
    string directions = MoveTower(numberOfRings, 'A', 'B', 'C');
    directions.pop_back();
    directions.pop_back();
    cout << "Directions for solving Towers of Hanoi with " << numberOfRings << " rings:" << endl;
    cout << directions << endl;
}


void TestRecursion()
{   
    vector<int> myVector{5, 10, 12, 15, 14};
    vector<int> theVector{myVector.begin(), myVector.end()};
    cout << "Sum of vectors <50, 10-12, 12, 15, 14>: " << SumVector(theVector) << endl;
    
    cout << "Converting 143 to binary: " << ConvertToBase(143, 2) << endl;
    cout << "Converting 143 to hexadecimal: " << ConvertToBase(143, 16) << endl;
    
    TowersOfHanoi(4);
}