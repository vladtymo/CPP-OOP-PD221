#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    string address;
    int* marks;
    int markCount;
    const int maxMark;

    void ClearResources()
    {
        if (marks != nullptr) delete[] marks;
        markCount = 0;
    }

public:
    Student(string name, string address, int max = 12)
        : name(name), address(address),
          marks(nullptr), markCount(0), maxMark(max) // initialization
    {
        // assing
        //maxMark = 12; // error
    }

    // copy constructor
    Student(const Student& other) : maxMark(other.maxMark)
    {
        this->name = other.name;
        this->address = other.address;
        this->markCount = other.markCount;

        // shallow copy
        //this->marks = other.marks;

        // deep copy
        this->marks = new int[markCount];
        for (size_t i = 0; i < markCount; i++)
        {
            this->marks[i] = other.marks[i];
        }
    }

    // destructor - invoke automatically when class instance is destroying
    ~Student()
    {
        ClearResources();
    }

    void Show() const
    {
        cout << "------- STUDENT -------\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;

        if (markCount > 0)
        {
            cout << "Marks: ";
            for (size_t i = 0; i < markCount; i++)
            {
                cout << marks[i] << " ";
            }
            cout << endl;
        }
    }

    void AddMark(int mark)
    {
        if (mark < 0 || mark > maxMark) return;

        // if marks is empty
        if (markCount == 0)
        {
            marks = new int(mark);
        }
        else
        {
            // create new array 
            int* newArr = new int[markCount + 1];

            // copy old elements
            for (size_t i = 0; i < markCount; i++)
                newArr[i] = marks[i];

            // add new mark to the end
            newArr[markCount] = mark;
            
            delete[] marks;
            marks = newArr;
        }
        // increment mark count
        ++markCount;
    }
};


int main()
{
    int a = 0;  // initialization
    a = 20;     // assing
    a = 30;     // assing

    Student st1("Oleg", "Soborna 5a");

    st1.AddMark(10);
    st1.AddMark(7);
    st1.AddMark(11);

    st1.Show();

    //Student st2(st1);
    Student st2 = st1;

    st2.Show();

    // clear resources
    //st1.ClearResources();
}