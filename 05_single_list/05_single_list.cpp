#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    List list;

    list.AddHead(6);
    list.AddHead(2);
    list.AddHead(10);
    list.AddHead(55);
    list.AddHead(87);

    list.Show();

    while (!list.IsEmpty())
    {
        cout << "Head: " << list.GetFirst() << endl;
        list.DeleteHead();
    }
}