#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree<long> tree;

    tree.Add(8);
    tree.Add(10);
    tree.Add(3);
    tree.Add(1);
    tree.Add(6);
    tree.Add(14);
    tree.Add(4);
    tree.Add(7);
    tree.Add(13);

    tree.ShowFromLeft();
    cout << "\n----------------\n";
    tree.ShowFromRight();
}