#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInList(int myList[], int size, int value)
{
    for (int i = 0; i < size; i++)
        if(myList[i] == value)
            return true;
    return false;
}

bool OrderedSequentialSearch(vector<int> sequence, int target)
{
    int pos;
    int low = 0;
    int high = sequence.size();
    
    while (high != low && low != sequence.size())
    {
        pos = low + (high - low) / 2;
        cout << "low = " << low << endl;
        cout << "high = " << high << endl;
        cout << "pos = " << pos << endl;
        if (sequence[pos] == target)
            return true;
        else if (sequence[pos] > target)
            high = pos;
        else
            low = pos;
    }
    return false;
}

void SearchAndHashing()
{
    int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
    vector<int> testvector(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    cout << "4 in list? " << OrderedSequentialSearch(testvector, 3) << endl;
    cout << "6 in list? " << OrderedSequentialSearch(testvector, 13) << endl; 
}