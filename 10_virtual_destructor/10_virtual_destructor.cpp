#include <iostream>
#include <initializer_list>
using namespace std;

class Person
{
private:
    string name;
    float height;
    string country;

public:
    Person() : name(""), height(0), country("Ukraine") { }
    Person(string name, float height, string country = "Ukraine")
        : name(name), height(height), country(country) 
    {
        cout << "Person constructor invokes!\n";
    }
    
    // pure virtual destructor
    virtual ~Person() = 0;

    virtual void Show() const
    {
        cout << "Name: " << name << endl;
        cout << "Height: " << height << "cm" << endl;
    }
};

class Student : public Person
{
private:
    int course;
    int* marks;
    int markCount;

public:
    Student() : Person(), course(1), marks(nullptr), markCount(0) { }
    Student(string name, float height, int course, initializer_list<int> marks)
        : Person(name, height), course(course), marks(nullptr), markCount(0) 
    {
        cout << "Student constructor invokes!\n";

        markCount = marks.size();
        this->marks = new int[markCount];

        int i = 0;
        for (const int* ptr = marks.begin(); ptr != marks.end(); ptr++)
        {
            this->marks[i++] = *ptr;
        }
    }

    ~Student()
    {
        cout << "Student destructor invokes!\n";
        delete[] marks;
    }

    void Show() const override
    {
        cout << "------- STUDENT -------\n";
        Person::Show();
        cout << "Course: " << course << endl;

        ShowMarks();
    }
    void ShowMarks() const
    {
        if (markCount > 0)
        {
            cout << "Marks: ";
            for (size_t i = 0; i < markCount; i++)
            {
                cout << marks[i] << " ";
            }
            cout << endl;
        }
        else cout << "There is no marks yet!\n";
    }

    void SetMark(int value)
    {
        if (marks == nullptr)
        {
            marks = new int[markCount + 1];
            marks[0] = value;
        }
        else
        {
            int* newArr = new int[markCount + 1];

            for (size_t i = 0; i < markCount; i++)
            {
                newArr[i] = this->marks[i];
            }
            newArr[markCount] = value;

            delete[] this->marks;
            this->marks = newArr;
        }
        ++markCount;
    }
};

int main()
{
    //Person person("Igor", 177); // abstract class with pure virtual destructor

    Person* student = new Student("Vasya", 183, 3, { 6, 10, 12, 10, 9, 8 });
    student->Show();

    /*student.SetMark(8);
    student.SetMark(11);
    student.SetMark(12);
    student.SetMark(9);
    student.ShowMarks();*/

    delete student;
}