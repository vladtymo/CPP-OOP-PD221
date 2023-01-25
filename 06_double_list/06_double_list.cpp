#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{
    List<short> list;

    list.InsertItem(111, 0);
    list.Show();

    list.AddHead(99);
    list.AddHead(1);
    list.AddHead(17);
    list.AddHead(3);
    list.AddHead(8);
    list.Show();

    list.InsertItem(222, 3);
    list.Show();
    list.InsertItem(333, 3);
    list.Show();

    list.AddTail(6);
    list.AddTail(2);
    list.AddTail(10);
    list.AddTail(55);
    list.AddTail(87);
    list.Show();

    list.InsertItem(444, 6);
    list.Show();
    list.InsertItem(555, 1);
    list.Show();
    list.InsertItem(666, 0);
    list.Show();
    list.InsertItem(777, list.GetCount());
    list.Show();

    cout << "Count: " << list.GetCount() << endl;
    list.Show();

    while (!list.IsEmpty())
    {
        cout << "-----------------------------------\n";
        cout << "Head: " << list.GetFirst() << endl;
        cout << "Tail: " << list.GetLast() << endl;
        //list.DeleteHead();
        list.DeleteTail();
    }

    cout << "Count: " << list.GetCount() << endl;

    // ------------ list with string items
    List<string> words;

    words.AddTail("red");
    words.AddTail("green");
    words.AddTail("blue");

    cout << "\nWords Count: " << words.GetCount() << endl;
    words.Show();
}