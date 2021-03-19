#include <iostream>
#include <queue>

using namespace std;


void HotPotato(string nameArray[], int arrayLength, int num)
{
    queue<string> nameQueue;
    
    // Fill initial queue
    for (int i = 0; i < arrayLength; i++)
        nameQueue.push(nameArray[i]);
    
    while (nameQueue.size() > 1)
    {
        for (int i = 0; i < num; i++)
        {
            nameQueue.push(nameQueue.front());
            nameQueue.pop();
        }
        cout << nameQueue.front() << " is out!" << endl;
        
        nameQueue.pop();
        cout << nameQueue.size() << " remaining" << endl;
    }
    
    cout << nameQueue.front() << " is the final person remaining" << endl;
}

void run_queue_tests()
{
    string names[] = {"Ash", "Cash", "Bash", "Dash", "Gash", "Nash"};
    int arrayLength = sizeof (names) / sizeof (names[0]);
    HotPotato(names, arrayLength, 2);
}




