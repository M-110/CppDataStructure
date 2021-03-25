#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isInList(int myList[], int size, int value)
{
    for (int i = 0; i < size; i++)
        if(myList[i] == value)
            return true;
    return false;
}

bool BinarySearch(vector<int> sequence, int target)
{
    int low = 0;
    int high = sequence.size() - 1;
    
    while (high >= low)
    {
        int pos = (high + low) / 2;
        if (sequence[pos] == target)
            return true;
        else if (sequence[pos] > target)
            high = pos - 1;
        else
            low = pos + 1;
    }
    return false;
}

int HashFunction(string a, int tableSize)
{
    int sum = 0;
    for (char pos : a)
        sum += int(pos);
    return sum % tableSize;
}

class Dictionary
{
public:
    static const int size = 11;
    int keys[size];
    string values[size];
    
    int HashFunction(int key)
    {
        return key % size;
    }
    
    int Rehash(int hash)
    {
        return (hash + 1) % size;
    }
    
    void put(int key, string value)
    {
        int hash = HashFunction(key);
        int count = 0;
        
        if (values[hash].empty())
        {
            keys[hash] = key;
            values[hash] = value;
        }
        
    }
    
};

void BinarySearchTests()
{
    int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
    vector<int> testVector(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    cout << "0 in list? " << BinarySearch(testVector, 0) << endl;
    cout << "42 in list? " << BinarySearch(testVector, 42) << endl; 
    cout << "100 in list? " << BinarySearch(testVector, 100) << endl; 
    cout << "-1 in list? " << BinarySearch(testVector, -1) << endl; 
}

void HashTests()
{
    cout << HashFunction("Dog", 10) << endl;
    cout << HashFunction("Cat", 10) << endl;
    cout << HashFunction("Wrench", 10) << endl;
}

void SearchAndHashing()
{
    // BinarySearchTests();
    HashTests();
}