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
    
    void Put(int key, string value)
    {
        int hash = HashFunction(key);
        int count = 0;
        if (values[hash].empty())
        {
            keys[hash] = key;
            values[hash] = value;
        }
        else
        {
            if (keys[hash] == key)
                values[hash] = value;
            else
            {
                int nextSlot = Rehash(hash);
                while (!values[nextSlot].empty() && keys[nextSlot] != key)
                {
                    nextSlot = Rehash(nextSlot);
                    count++;
                    if (count > size)
                    {
                        cout << "Dictionary is full. (" << count << " keys)" << endl;
                    }
                }
                if (!values[nextSlot].empty())
                {
                    keys[nextSlot] = key;
                    values[nextSlot] = value;
                }
                else
                    values[nextSlot] = value;
            }
        }
    }
    
    string Get(int key)
    {
        int startSlot = HashFunction(key);
        
        string val;
        bool stop = false;
        bool found = false;
        int position = startSlot;
        
        while(!values[position].empty() && !found && !stop)
        {
            if (keys[position] == key)
            {
                found = true;
                val = values[position];
            }
            else
            {
                position = Rehash(position);
                if (position == startSlot)
                    stop = true;
            }
        }
        return val;
    }
    friend ostream& operator<<(ostream& stream, Dictionary& hash);
};



ostream& operator<<(ostream& stream, Dictionary& hash) {
    for (int i=0; i<hash.size; i++) {
        stream<<hash.keys[i]<<": "<<hash.values[i]<<endl;
    }

    return stream;
}

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
    
    Dictionary dict;

    dict.Put(54, "cat");
    dict.Put(26, "dog");
    dict.Put(93, "lion");
    dict.Put(17, "tiger");
    dict.Put(77, "bird");
    dict.Put(31, "cow");
    dict.Put(44, "goat");
    dict.Put(55, "pig");
    dict.Put(20, "chicken");
    cout << dict << endl;
}

void SearchAndHashing()
{
    BinarySearchTests();
    HashTests();
}