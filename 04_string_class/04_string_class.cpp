#include <iostream>
using namespace std;

class String
{
private:
    int length;
    char* symbols;

public:
    String() : length(0), symbols(nullptr) { }
    String(char symbol, int count = 1)
    {
        length = count;
        symbols = new char[length];
        for (size_t i = 0; i < length; i++)
        {
            symbols[i] = symbol;
        }
    }
    explicit String(const String& other)
    {
        this->length = other.length;
        this->symbols = new char[length];
        for (size_t i = 0; i < length; i++)
        {
            symbols[i] = other.symbols[i];
        }
    }
    ~String()
    {
        delete[] symbols;
    }

    void Replace(char oldS, char newS)
    {
        for (size_t i = 0; i < length; i++)
        {
            if (symbols[i] == oldS) symbols[i] = newS;
        }
    }
    void Append(char s)
    {
        char* newStr = new char[length + 1];

        for (size_t i = 0; i < length; i++)
        {
            newStr[i] = symbols[i];
        }
        newStr[length] = s;

        delete[] symbols;
        symbols = newStr;

        ++length;
    }
    void Clear()
    {
        delete[] symbols;
        symbols = nullptr;
        length = 0;
    }

    void Print() const
    {
        for (size_t i = 0; i < this->length; i++)
        {
            cout << symbols[i];
        }
    }
    void PrintLine() const
    {
        this->Print();
        cout << endl;
    }
};

int main()
{
    String str1('#', 10);
   
    str1.Append('!');
    str1.PrintLine();

    String str2(str1); // copy constructor

    str2.Replace('#', '*');
    str2.Append('?');
    str2.PrintLine();

    //String str3('$');  // explicit invoke
    String str3 = '$'; // implicit invoke
    str3.PrintLine();
}