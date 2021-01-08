#include <iostream>
using namespace std;


class node
{
public:
    int value;
    int key;
    node()
    {
        value = -1;
        key = -1;
    }
    
    node(int k, int v)
    {
        value = v;
        key = k;
    }
};


class HashTable
{
    
    node** arr;
    int capacity;
    int size;
    node* dummy;

public:
    HashTable()
    {
        
        capacity = 20;
        size = 0;
        arr = new node*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = NULL;
        }
       
        dummy = new node;
    }
    
    int hashCode(int key)
    {
        return key % capacity;
    }

    
    void insertNode(int key, int value)
    {
        node * temp = new node(key, value);

        
        int hashIndex = hashCode(key);

        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key&& arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    
    int deleteNode(int key)
    {
        
        int hashIndex = hashCode(key);

        
        while (arr[hashIndex] != NULL)
        {
           
            if (arr[hashIndex]->key == key)
            {
                node* temp = arr[hashIndex];

               
                arr[hashIndex] = dummy;

               
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;

        }

        
        return 0;
    }

    
    int search(int key)
    {
        
        int hashIndex = hashCode(key);
        int counter = 0;
           
        while (arr[hashIndex] != NULL)
        {
            int counter = 0;
            if (counter++ > capacity)  
                return 0;
            
            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        
        return 0;
    }

    
    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
            {
                cout << "key = " << arr[i]->key << "  value = " << arr[i]->value << endl;
            }
        }
    }
};


int main()
{
    HashTable* h = new HashTable;
    int loopInput;
    while (1)
    {
        cout << "Press 1 to insert into Hash Table using open addressing" << endl;
        cout << "Press 2 to Delete key from Hash Table using open addressing" << endl;
        cout << "Press 3 to search the Hash Table using open addressing" << endl;
        cout << "Press 4 to display the Hash Table using open addressing" << endl;
        cout << "Press 5 to to end" << endl;
        cin >> loopInput;

        if (loopInput == 1)
        {
            int vkey, vvalue;
            cout << "Enter Key = ";
            cin >> vkey;
            cout << "Enter Value = ";
            cin >> vvalue;
            h->insertNode(vkey, vvalue);

        }
        else if (loopInput == 2)
        {
            int vkey;
            cout << "Enter a key to delete = ";
            cin >> vkey;
            int vtemp;
            vtemp = h->deleteNode(vkey);
            if (vtemp == 0)
            {
                cout << "This key doesn't exist, so cant delete it" << endl;
                system("pause");
                system("cls");
                continue;
                
            }
            else
            {
                cout << "Deleting " << vtemp << endl;
            }
           
        }
        else if (loopInput == 3)
        {
            int vkey;
            cout << "Enter a key to search = ";
            cin >> vkey;
            if (h->search(vkey) == 0)
            {
                cout << "Key not found, please try again" << endl;
                system("pause");
                system("cls");
                continue;
                
            }
            cout << "Key Found, Following is its value" << endl;
            cout << h->search(vkey) << endl;
        }
        else if (loopInput == 4)
        {
        
            h->display();
        }
        else if (loopInput == 5)
        {
            break;
        }
        system("pause");
        system("cls");
    }

   

    return 0;
}

