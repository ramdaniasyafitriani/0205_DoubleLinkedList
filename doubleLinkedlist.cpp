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
