#include<iostream>
#include <iomanip>
using namespace std;
const int starting_cnic[3] = { 38601, 7891234, 1 };
class node
{
public:
    int data;
    node* next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class linklist
{
public:
    node* head;
    linklist()
    {
        head = NULL;
    }

    void push(int key)
    {
        node* temp = new node;
        temp->data = key;
        temp->next = head;
        head = temp;
    }
    void deleteNode(int key)
    {
        node* temp = head;
        node* temp2 = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << temp->data;
                if (head->next == NULL)
                {
                    head = NULL;
                    break;
                }

                else
                {
                    if (temp == head)
                    {
                        head = head->next;
                    }
                    else
                    {
                        while (temp2->next != temp)
                        {
                            temp2 = temp2->next;
                        }
                        temp2->next = temp->next;
                        delete temp;
                    }

                    break;

                }
            }
            temp = temp->next;
        }

    }
    bool search(int x)
    {
        bool checker = false;
        node* temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                checker = true;
                break;
            }
            temp = temp->next;
        }
        return checker;
    }
    void display()
    {

        if (head == NULL)
        {
            return;
        }
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};


class Hash
{
    int BUCKET;
    linklist* table;
public:
    Hash(int V)
    {

        this->BUCKET = V;
        table = new linklist[BUCKET];

    }


    void insert(int x)
    {
        int index = hash_Function(x);
        table[index].push(x);
    }
    void Delete(int temp3)
    {
        bool checker2 = false;
        for (int i = 0; i < BUCKET; i++)
        {
            if (table[i].search(temp3) == true)
            {
                checker2 = true;
                cout << endl;
                cout << "Value Found at Index " << i << endl;
            }
        }
        if (checker2 == false)
        {
            cout << endl;
            cout << "Value Not Found, Please Try Again" << endl;
        }
        else
        {
            int index = hash_Function(temp3);
            cout << "38106 ";
            table[index].deleteNode(temp3);
            cout << " ";
            table[index].deleteNode(index);
            cout << endl;
            cout << endl;

            BUCKET--;
        }
    }
    void Search()
    {
        int input;
        int temp1;
        cout << "Press 1 to search by Middle Code of CNIC" << endl;
        cout << "Press 2 to search by Last(Gender) Code of CNIC" << endl;
        cin >> input;
        if (input == 1)
        {
            bool checker2 = false;
            cout << "Enter Middle Code =";
            cin >> temp1;
            for (int i = 0; i < BUCKET; i++)
            {
                if (table[i].search(temp1) == true)
                {
                    checker2 = true;
                    cout << endl;
                    cout << "Value Found at Index " << i << endl;
                }
            }
            if (checker2 == false)
            {
                cout << endl;
                cout << "Value Not Found, Please Try Again" << endl;
            }
        }
        else if (input == 2)
        {
            bool checker2 = false;
            cout << "Enter Last(Gender) Code";
            cin >> temp1;
            for (int i = 0; i < BUCKET; i++)
            {
                if (table[i].search(temp1) == true)
                {
                    checker2 = true;
                    cout << endl;
                    cout << "Value Found at Index "<<i << endl;
                }
            }
            if (checker2 == false)
            {
                cout << endl;
                cout << "Value Not Found, Please Try Again" << endl;
            }
        }
    }


    int hash_Function(int key)
    {
        return (key % 15);
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            if (table[i].head == NULL)
            {
                continue;
            }
            cout << setw(2) << i << " |";
            cout << "38601 ";
            table[i].display();
            cout << endl;
        }

    }
};



int main()
{
    int loopInput;
    int counter1 = 38601;
    int counter2 = 7891234;
    int counter3 = 1;
    int cnic[15][3];
    for (int i = 0; i < 15; i++)
    {
        cnic[i][0] = counter1;
        cnic[i][1] = counter2;
        cnic[i][2] = counter3;
        counter2++;
        counter3++;
        if (counter3 > 9)
        {
            counter3 = 2;
        }
    }

    int key[3];
    key[0] = 38601;
    key[1] = 15;
    key[2] = 9;
    Hash h(key[1]);
    while (1)
    {
        cout << "Press 1 to store 15 CNICs in Hash Table Through Separate Chaining" << endl;
        cout << "Press 2 to Display All CNICs" << endl;
        cout << "Press 3 to Search A CNIC" << endl;
        cout << "Press 4 to Delete a CNICs" << endl;
        cout << "Press 5 to end" << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {

            for (int i = 0; i < 15; i++)
            {
                h.insert(cnic[i][1]);
                h.insert(cnic[i][2]);
            }
            cout << endl;
            cout << "Insertion Successful" << endl;
        }
        else if (loopInput == 2)
        {
            cout << endl;
            h.displayHash();
            cout << endl;
            
        }
        else if (loopInput == 3)
        {
            h.Search();       
        }
        else if (loopInput == 4)
        {
            int temp3;
            cout << "Enter Middle Code of CNIC to delete it = ";
            cin >> temp3;
            h.Delete(temp3);
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
