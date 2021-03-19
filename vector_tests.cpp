#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void test1(int num)
{
    vector <int> vect;

    for (int i = 0; i < num; i++)
        vect.push_back(i);
}

void test2(int num)
{
    vector<int> vect2;
    vect2.reserve(num);
    for (int i = 0; i < num; i++)
        vect2.push_back(i);
}

void test_time()
{
    int numRuns = 10000;

    // RUN 1
    clock_t begin_t1 = clock();
    for (int i = 0; i < numRuns; i++)
        test1(numRuns);

    clock_t end_t1 = clock();
    double elapsed_seconds = double(end_t1 - begin_t1) / CLOCKS_PER_SEC;

    cout << fixed << endl;
    cout << "push_back " << elapsed_seconds << " milliseconds" << endl;

    // RUN 2
    clock_t begin_t2 = clock();
    for (int i = 0; i < numRuns; i++)
        test2(numRuns);

    clock_t end_t2 = clock();
    double elapsed_seconds2 = double(end_t2 - begin_t2) / CLOCKS_PER_SEC;

    cout << fixed << endl;
    cout << "push_back " << elapsed_seconds2 << " milliseconds" << endl;
}