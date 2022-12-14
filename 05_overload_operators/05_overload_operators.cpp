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

    // static fields
    static string type; // create once only

    friend void operator<<(ostream&, const Kettle&);
    friend void operator>>(istream&, Kettle&);
public:
    Kettle() : model(""), color(""), volume(0), isPowerOn(false) { }
    Kettle(string m, string c, float v) : model(m), color(c), volume(v), isPowerOn(false) { }
    Kettle(const Kettle& other) = default;

    void SwitchPower()
    {
        isPowerOn = !isPowerOn;
    }
    void ShowInfo() const
    {
        cout << "----------- Kettle: " << model << " -----------\n";
        cout << "Color: " << color << endl;
        cout << "Volume: " << volume << "ml" << endl;
        cout << "Power: " << (isPowerOn ? "ON" : "OFF") << endl;
        cout << "Type: " << this->type << endl;
    }

    // static methods - does not have this pointer
    // has access to static fields only
    static string GetType()
    {
        return type;
    }
    static void SetType(string value)
    {
        type = value;
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
    Kettle& operator++()
    {
        this->volume += 50;
        return *this;
    }
    Kettle& operator--()
    {
        if (this->volume >= 50)
            this->volume -= 50;
        return *this;
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

    // input / output operators
    // operation: ostream << Kettle
};

// ------- overload operators using global funcitons
// operator [<<]: ostream << Kettle
void operator<<(ostream& os, const Kettle& kettle)
{
    os << "----------- Kettle: " << kettle.model << " -----------\n";
    os << "Color: " << kettle.color << endl;
    os << "Volume: " << kettle.volume << "ml" << endl;
    os << "Power: " << (kettle.isPowerOn ? "ON" : "OFF") << endl;
}
void operator>>(istream& cin, Kettle& kettle)
{
    cout << "Enter model: ";
    cin >> kettle.model;
    cout << "Enter color: ";
    cin >> kettle.color;
    cout << "Enter volume: ";
    cin >> kettle.volume;
}

// initialize static fields
string Kettle::type = "Some type";

int main()
{
    int a = 6, b = 10;
    cout << a + b << endl;
    cout << -a << endl;
    cout << ++a << endl;

    int c = ++a;
    int d = a = b;

    string strA = "hello", strB = "bye";
    cout << strA + strB << endl;

    // invoke static methods
    Kettle::SetType("New type");
    cout << "Type: " << Kettle::GetType() << endl;

    // -----------------------
    Kettle myKettle("Phillips", "White", 1800);
    myKettle.ShowInfo();

    Kettle yourKettle("Tefal", "Black", 1250);
    yourKettle.ShowInfo();

    //Kettle superKettle = myKettle.Add(yourKettle);
    Kettle superKettle = myKettle + yourKettle;
    superKettle.ShowInfo();
    
    ++superKettle;
    Kettle other = ++superKettle;

    superKettle.ShowInfo();

    if (myKettle > yourKettle)
        cout << "My kettle is bigger than your!\n";
    else
        cout << "My kettle is not bigger than your!\n";

    // operator [=]
    //myKettle = superKettle; // delete function (operator=)
    //myKettle.ShowInfo();

    // operator [>>]
    cin >> myKettle;

    // operator [<<]
    cout << myKettle;
}
