#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    List list;

    list.AddTail(6);
    list.AddTail(2);
    list.AddTail(10);
    list.AddTail(55);
    list.AddTail(87);

    cout << "Count: " << list.GetCount() << endl;
    list.Show();

    while (!list.IsEmpty())
    {
        cout << "-----------------------------------\n";
        cout << "Head: " << list.GetFirst() << endl;
        cout << "Tail: " << list.GetLast() << endl;
        list.DeleteHead();
    }

    cout << "Count: " << list.GetCount() << endl;
}