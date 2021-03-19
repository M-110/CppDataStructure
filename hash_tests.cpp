#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
using namespace std;


void test_hash()
{
    for (int size = 1000; size < 10000000; size += 2000000)
    {
        // Vector test

        vector<int> testVector;
        clock_t beginVector = clock();
        for (int i = 0; i < size; i++)
            testVector.push_back(i);
        clock_t endVector = clock();
        double elapsedSecondsVector = double(endVector - beginVector) / CLOCKS_PER_SEC;

        // Hash test

        unordered_map<int, int> hashTest;
        clock_t beginHash = clock();
        for (int j = 0; j < size; j++)
            hashTest[j] = 0;
        clock_t endHash = clock();
        double elapsedSecondsHash = double(endHash - beginHash) / CLOCKS_PER_SEC;

        // Output
        cout << fixed << endl;
        cout << "Size " << size << ": Vector(" << elapsedSecondsVector <<
        ")\t Hash(" << elapsedSecondsHash << ")" << endl;
    }

}


