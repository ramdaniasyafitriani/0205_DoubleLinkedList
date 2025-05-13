#include <iostream>
using namespace std;

// membuat struktur untuk object double linked list
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarasi pointer next dan prev untuk penunjukan data sebelum dan sesudah
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemberian nilai 
Node *START = NULL;

// deklarasi prosedur addNode 
void addNode()
{

    // pembuatan node dan pemberian value untuk data noMhs dan name 
    Node *newNode = new Node(); // step 1 buat Node baru
    cout << "\nEnter the roll nnumber of the student : ";
    cin >> newNode->noMhs; // assign value to the data field of the new node
    cout << "\nEnter the name of the student : "; 
    cin >> newNode->name; // assign value to the data field of the new node

    // insert the new node in the list 
    // kondisi jika start == null atau noMhs node baru <= noMhs Start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning 
        // kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return; 
        }
        // if the list is empty, make the new node the START
        // jika list kosong, maka Node nextnya adalah START
        newNode->next = START; // step 3: make the new node point to the first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong 
        if (START != NULL)
        {
            START->prev = newNode; // step 4: make the first node point to the node
        }
        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make the new Node point to NUll
        START = newNode;      // step 6: make the new node the first node
    }
 