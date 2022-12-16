#include <iostream>
using namespace std;

class Person
{
private:    // accessible from this class only
    float weight;
    float height;
    int age;
    string country;

protected:  // accessible from this class and from the inherited classes
    string name;

public:     // accessible from outside the class
    Person() : Person("", 0, 0, 0, "") { }
    Person(string n, float w, float h, int a, string c)
        : name(n), country(c)
    {
        // (condition) ? value1 : value2;
        this->weight = w > 0 ? w : 0;
        this->height = h > 0 ? h : 0;
        this->age = a > 0 ? a : 0;
    }

    void Speek() const
    {
        cout << "Blablalba, I am " << name << "...\n";
    }
    string GetShortInfo() const
    {
        return name + " from " + country;
    }
    void ShowInfo() const
    {
        cout << "----------- " << name << " -----------\n";
        cout << "Name: " << name << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Height: " << height << "cm" << endl;
        cout << "Age: " << age << endl;
        cout << "Country: " << country << endl;
    }
};

// Inheritance - feature or a process in which, new classes are created from the existing classes
// Syntax: class Child : <specifier> Parent
// Inheritance specifier is private by default
class Employee : public Person
{
private:
    double salary;
    string position;

public:
    Employee() : salary(0), position(""), Person() // invoke base class constructor
    { }
    Employee(string n, float w, float h, int a, string c, double s, string p)
        : Person(n, w, h, a, c)
    {
        this->position = p;
        this->salary = s > 0 ? s : 0;
    }

    void DoWork() const
    {
        cout << "I am " << name << " and I am working...\n";
    }
    void PayTaxes()
    {
        cout << "Paying taxes...\n";
        salary -= 10;
    }
    void ShowInfo() const
    {
        Person::ShowInfo(); // invoke base class method
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << "$" << endl;
    }
};

class Programmer : public Employee
{
private:
    int wroteLines;
    string programmingLang;

public:
    Programmer() : wroteLines(0), programmingLang(""), Employee() { }

    Programmer(string n, float w, float h, int a, string c, double s, string p, string l)
        : Employee(n, w, h, a, c, s, p), wroteLines(0), programmingLang(l) { }

    void WriteCodeLine()
    {
        cout << name << ": writing a code line on " << programmingLang << "...!\n";
        ++wroteLines;
    }
    void ShowInfo() const
    {
        Employee::ShowInfo();
        cout << "Programming Langiage: " << programmingLang << endl;
    }
};

int main()
{
    Person person("Igor", 70, 190, 20, "Ukraine");

    cout << person.GetShortInfo() << "!\n";
    person.ShowInfo();

    person.Speek();

    //-----------------------------

    Employee emp("Sofia", 60, 175, 31, "Ukraine", 1200, "Software Engineer");

    emp.ShowInfo();
    emp.DoWork();
    emp.PayTaxes();
    emp.Speek();

    //----------------------------

    Programmer prog("Oleg", 88, 184, 39, "Italy", 3400, "Senior Software Engineer", "C++");

    prog.ShowInfo();
    prog.WriteCodeLine();
}