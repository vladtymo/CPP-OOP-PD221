#include "Vector.h"

int main()
{
    Vector<int> vector;
    cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;

    vector.Push(567);
    cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;

    vector.Unshift(123);
    cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;

    for (size_t i = 0; i < 35; i++)
    {
        vector.Push(rand() % 10);
        cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;
    }

    vector.ShrinkToFit();
    cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;

    vector.Push(567);
    cout << "Size: " << vector.GetSize() << " of " << vector.GetCapacity() << endl;

    vector.Show("Original array");

    vector.Clear();

    vector.Show("Cleared array");
}