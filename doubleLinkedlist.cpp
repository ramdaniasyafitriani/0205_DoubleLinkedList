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
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {
        // insert the new node in the middle or at the end
        // set nilai current = start dan nilai previous = null
        Node *current = START; // step 1.a: start from the first node
        Node *previous = NULL; // step 1.b: previous node is Null initially

        // Looping selama current != NULL dan noMhs dari current lebih kecil
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                             // step 1.c: traverse the list to find the 
            previous = current;      // step 1.d: move the previous to the current
            current = current->next; // step 1.e: move the current to the next node
        }

        // set nilai next node baru = current dan prev node baru = previous 
        newNode->next = current; // step 4: make the next field of the new node
        newNode->prev = previous; // step 5: make the previous field of the new node

        // kondisi jika current tidak sama dengan Null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the current node
        }

        // kondisi jika previous tidak sama dengan null 
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next field to previous
        }
        // kondisi jika if previous sama dengan null
        else 
        {
            // if previous is still null, it means newNode is now the first node
            START = newNode;
        }
    }
}

// pembuatan function search untuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

// pembuatan prosedure delete untuk menghapus data
void deleteNode()
{
   Node *previous, *current;
   int rollNo;
   
   cout << "\nEnter the roll number of the student whose record is to be deleted : " << endl;
   cin >> rollNo; // step 3: get the roll number number to be deleted

   if (START == NULL)
   {
        cout << "List is empty" << endl;
        return;
   }

   current = START; // step 1: start from the first node
   previous = NULL; 

   // Located the node to be deleted 
   while (current != NULL && current->noMhs != rollNo)
   {
    cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
    return;
   }

   // node to be deleted in the first node 
   if (current =START)
   {
        START = START->next; // step 2: update the START pointer 
        if (START != NULL)
        {
            START->prev = NULL;
        }
   }
   else 
   { // node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        { // if there's a successor, update its prev pointer
            current->next->prev = previous;
        }
   }
   // relase the memory of the node marked as current
   delete current;
   cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m " << endl;
}

// method untuk mengecek apakah list kosong
bool listEmpty()
{
    return (START == NULL);
}

// prosedur traverse untuk menampilkan data secara urut 
void traverse()
{
    if (listEmpty())
        cout << "\nList is Empty " << endl;
  
    else
    {
        cout << "\nData didalam list adalah :\n";
        Node *currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}

// prosedur untuk menampilkan data secara urutan terbalik
void revtraverse()
{
    if (listEmpty())
        cout << "\nList is Empty " << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are : " << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

// prosedur untuk mencari data dan menampilkan data yang dicari jika ada
void searchData()
{
    if (listEmpty())
    {
        cout << "\nList is Empty " << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search : ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found " << endl;
    else
    {
        cout << "\nRecord found " << endl;
        cout << "\nRoll number : " << curr->noMhs << endl;
        cout << "\nName : " << curr->name << endl;
    }
}

int main()
{
    // perulangan selama bernilai benar untuk program utama double linkedlist
    while (true)
    {
        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Menambah data kedalam list " << endl;
            cout << "2. Menghapus data dari dalam list " << endl;
            cout << "3. view all records in the ascending order of roll numbers " << endl;
            cout << "4. view all records in the descending order of roll numbers " << endl;
            cout << "5. Search for a record in the list " << endl;
            cout << "6. Keluar" << endl;
            cout << "Masukkan pilihan (1-6): ";
            char ch;
            cin >> ch;

            switch (ch)
            {
            case '1':
                addNode();
                break;
            case '2' : 
                deleteNode();
                break;
            case '3':
                traverse();
                break;
            case '4':
                revtraverse();
                break;
            case '5' : 
                searchData();
                break;
            case '6' :
                return 0;
            default :
                cout << "\nInvalid option " << endl;
                break;
                
            }
        }
        catch (exception &e)
        {
            cout << " Check for the values entered." << endl;
        }
        
    }
}