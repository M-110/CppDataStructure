#include <iostream>
using namespace  std;

class Node
{
    private:
        int data;
        Node *next;
    
    public:
        Node(int initialData)
        {
            data = initialData;
            next = nullptr;
        }
        
        int GetData()
        {
            return data;
        }
        
        Node *GetNext()
        {
            return next;
        }
        
        void SetData(int newData)
        {
            data = newData;
        }
        
        void SetNext(Node *newNext)
        {
            next = newNext;
        }
};

class UnorderedList
{
    public:
        Node *head;
        
        UnorderedList()
        {
            head = nullptr;
        }
        
        bool IsEmpty()
        {
            return head == nullptr;
        }
        
        int Size()
        {
            if (IsEmpty())
                return 0;
            
            int count = 1;
            
            Node *nextNode = head;
            
            while (nextNode->GetNext() != nullptr)
            {
                count++;
                nextNode = nextNode->GetNext();
            }
            return count;
        }
        
        bool Search(int n)
        {
            if (IsEmpty())
                return false;
            Node *nextNode = head;

            if (nextNode->GetData() == n)
                return true;
            
            while (nextNode->GetNext() != nullptr)
            {
                nextNode = nextNode->GetNext();
                if (nextNode->GetData() == n)
                    return true;
            }
            return false;
        }
        
        
        void Add(int n)
        {
            Node *newNode = new Node(n);
                    
            if (IsEmpty())
                head = newNode;
            else
            {
                newNode->SetNext(head);
                head = newNode;
            }
        }
        
        void Remove(int n)
        {
            if (!Search(n)) return;
            
            if (head->GetData() == n)
                head = head->GetNext();
            Node *prevNode = head;
            Node *nextNode = head->GetNext();
            while (nextNode->GetNext() != nullptr)
            {
                if (nextNode->GetData() == n)
                {
                    prevNode->SetNext(nextNode->GetNext());
                    delete nextNode;
                    return;
                }
                prevNode = nextNode;
                nextNode = nextNode->GetNext();
            }
        }
};

void ConstructList()
{
    UnorderedList list = UnorderedList();
    
    list.Add(24);
    list.Add(9);
    list.Add(5);
    list.Add(6);
    list.Add(7);
    list.Add(3);
    list.Add(34);

    Node *node = list.head;

    while (node->GetNext() != nullptr)
    {
        cout << node->GetData() << endl;
        node = node->GetNext();
    }
    cout << node->GetData() << endl;
    


    cout << "Is 5 in list? " << list.Search(5) << endl;
    cout << "Is 12 in list? " << list.Search(12) << endl;
    cout << "Is 6 in list? " << list.Search(6) << endl;
    
    cout << "Size: " << list.Size() << endl;
    cout << "Removing 6" << endl;
    
    list.Remove(6);
    
    cout << "Is 6 in list? " << list.Search(6) << endl;
    
    cout << "size after removal: " << list.Size() << endl;

}