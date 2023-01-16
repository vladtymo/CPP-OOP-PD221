#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class MyArray
{
    int* arr;
    int size;
public:
    MyArray(int size = 0)
    {
        if (size < 0) throw invalid_argument("Size can not be less than zero");

        if (size != 0)
        {
            this->size = size;
            arr = new int[size] { 0 };
        }
        else
        {
            this->size = 0;
            arr = nullptr;
        }
    }
    ~MyArray()
    {
        delete[] arr;
    }

    void Fill(int value = 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            this->arr[i] = value;
        }
    }

    // access element by index
    void SetValue(int index, int value)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range.");
        arr[index] = value;
    }
    int GetValue(int index) const 
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range.");
        return arr[index];
    }

    void Resize(int newSize)
    {
        if (newSize < 0) throw invalid_argument("Size can not be less than zero");

        if (newSize == 0)
        {
            delete[] arr;
            arr = nullptr;
        }
        else
        {
            int* newArr = new int[newSize] { 0 };
            for (size_t i = 0; i < size && i < newSize; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] this->arr;
            this->arr = newArr;
        }
        this->size = newSize;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    void Show() const
    {
        if (IsEmpty()) throw exception("Array is empty"); //cout << "Array is empty!\n";
        else
        {
            cout << "Array: ";
            for (size_t i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    try
    {
        //throw 1002;

        MyArray arr(-10);                                 // invalid_argument

        arr.SetValue(33, 89);                            // out_of_range
        cout << "New item: " << arr.GetValue(7) << endl; // out_of_range

        arr.Resize(15);                                  // invalid_argument

        arr.Show();                                      // exception
    }
    catch (const std::out_of_range& ex)
    {
        cout << "type: out_of_range\n";
        cout << ex.what() << endl;
    }
    catch (const std::invalid_argument& ex)
    {
        cout << "type: invalid_argument\n";
        cout << ex.what() << endl;
    }
    catch (const std::exception& ex)
    {
        cout << "type: exception\n";
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Invalid exception type!\n";
    }
    
    cout << "------------------------------\n";
    cout << "Continue...\n";
}