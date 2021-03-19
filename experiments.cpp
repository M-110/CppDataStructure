#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>
using namespace std;


void index_test()
{
    cout << "Testing index operator speed for vectors:";
    cout << fixed << endl;
    for (int size = 10000; size < 100000; size += 10000)
    {
        //Create Vector of size Size
        vector<int> vectorTest;
        vectorTest.reserve(size);
        for (int i = 0; i < size; i++)
            vectorTest.push_back(i);

        //Time
        int x = 0;
        clock_t start = clock();
        for (int j = 0; j < 1000000; j++)
            x = vectorTest[500];
        clock_t end = clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;

        cout << "Size " << size << ": " << elapsed << endl;
    }
    cout << "Time stays constant as Size increases. O(1) complexity shown" << endl << endl;
}

void insert_hash_test()
{
    cout << "Testing find operator speed for hash tables:";
    cout << fixed << endl;
    for (int size = 10000; size < 100000; size += 10000)
    {
        //Create Hash table of size Size
        unordered_map<int, int> hashTest;
        for (int i = 0; i < size; i++)
            hashTest[i] = 1;

        //Time
        int x = 0;
        clock_t start = clock();
        for (int j = 0; j < 1000000; j++)
            x = hashTest[500];
        clock_t end = clock();
        double elapsed = double(end - start) / CLOCKS_PER_SEC;

        cout << "Size " << size << ": " << elapsed << endl;
    }
    cout << "Time stays constant as Size increases. O(1) complexity shown" << endl << endl;
}

void erase_test()
{
    cout << "Testing the performance of erase for vectors and hash tables:";
    cout << fixed << endl;
    cout << "Size\t\tVector\t\tHash" << endl;
    for (int size = 10000; size < 1000000; size += 100000)
    {
        //Create Hash table of size Size
        unordered_map<int, int> hashTest;
        for (int i = 0; i < size; i++)
            hashTest[i] = 1;

        //Create Vector of size Size
        vector<int> vectorTest;
        vectorTest.reserve(size);
        for (int i = 0; i < size; i++)
            vectorTest.push_back(i);

        //Vector Timer
        clock_t startVector = clock();
        for (int j = 0; j < 10000; j++)
            vectorTest.erase(vectorTest.begin() + 0);
        clock_t endVector = clock();
        double elapsedVector = double(endVector - startVector) / CLOCKS_PER_SEC;

        //Hash table Timer
        clock_t startHash = clock();
        for (int j = 0; j < 10000; j++)
            hashTest.erase(j);
        clock_t endHash = clock();
        double elapsedHash = double(endHash - startHash) / CLOCKS_PER_SEC;

        cout << size << "\t\t" << elapsedVector << "\t\t" << elapsedHash << endl;
    }
    cout << "Erase is O(n) for Vector, but O(1) for Hash" << endl << endl;
}

void run_experiments()
{
    index_test();
    insert_hash_test();
    erase_test();
}