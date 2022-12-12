#include <iostream>
#include <string>
using namespace std;

class Kettle
{
private:
    float volume;
    string model;
    string color;
    bool isPowerOn;

public:
    Kettle() : model(""), color(""), volume(0), isPowerOn(false) { }
    Kettle(string m, string c, float v) : model(m), color(c), volume(v), isPowerOn(false) { }
    Kettle(const Kettle& other) = default;

    void ShowInfo() const
    {
        cout << "----------- Kettle: " << model << " -----------\n";
        cout << "Color: " << color << endl;
        cout << "Volume: " << volume << "ml" << endl;
        cout << "Power: " << (isPowerOn ? "ON" : "OFF") << endl;
    }

    Kettle Add(const Kettle& other) const
    {
        // result = this + other
        return Kettle(this->model, this->color, this->volume + other.volume);
    }
    
    // -=-=-=-=-=-=-=-=- Operator Overloading -=-=-=-=-=-=-=-=-
    /*
        return_type operator[symbol](parameters) { }
    */

    // Unary operators - works with only one operand (this): ++ -- -
    void operator++()
    {
        this->volume += 50;
    }
    void operator--()
    {
        if (this->volume >= 50)
            this->volume -= 50;
    }
    
    // Binary opertors - works with two operands: + - * / > < >= <= == != =
    // this		 - left operand
    // parameter - right operand
    Kettle& operator=(const Kettle& other) = delete;

    Kettle operator+(const Kettle& other) const
    {
        // result = this + other
        return Kettle(this->model, this->color, this->volume + other.volume);
    }

    bool operator<(const Kettle& other) const
    {
        // this < other
        return this->volume < other.volume;
    }
    bool operator>(const Kettle& other) const
    {
        // this < other
        return !(*this < other);
    }
};

int main()
{
    int a = 6, b = 10;
    cout << a + b << endl;
    cout << -a << endl;
    cout << ++a << endl;

    string strA = "hello", strB = "bye";
    cout << strA + strB << endl;

    // -----------------------
    Kettle myKettle("Phillips", "White", 1800);
    
    myKettle.ShowInfo();

    Kettle yourKettle("Tefal", "Black", 1250);
    yourKettle.ShowInfo();

    //Kettle superKettle = myKettle.Add(yourKettle);
    Kettle superKettle = myKettle + yourKettle;
    superKettle.ShowInfo();

    ++superKettle;
    superKettle.ShowInfo();

    if (myKettle > yourKettle)
        cout << "My kettle is bigger than your!\n";
    else
        cout << "My kettle is not bigger than your!\n";

    // operator [=]
    //myKettle = superKettle; // delete function (operator=)
    //myKettle.ShowInfo();
}
