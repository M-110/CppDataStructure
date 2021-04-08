#include <iostream>
#include <vector>
using namespace std;



vector<int> BubbleSort(vector<int> myArray)
{
    int temp;
    bool sorted;
    for (int j = myArray.size(); j > 0; j--)
    {
        sorted = true;
        for (int i = 0; i < j - 1; i++)
            if (myArray[i] > myArray[i + 1])
            {
                temp = myArray[i];
                myArray[i] = myArray[i + 1];
                myArray[i + 1] = temp;
                sorted = false;
            }
        if (sorted)
        {
            cout << "Breaking out early" << endl;
            return myArray;
        }
    }
    return myArray;
}

void BubbleSortTest() 
{
    // Vector initialized using a static array
    static const int arr[] = {54,26,93,17,77,31,44,55,20};
    vector<int> aVector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<int> bVector = BubbleSort(aVector);
    for (int i : bVector) {
        cout<<i<< " ";
    }
}  


void SortFunctions() 
{
    BubbleSortTest();
}              