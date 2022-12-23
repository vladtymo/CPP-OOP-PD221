#include <iostream>
#include <string>
using namespace std;

// abstract class - has at least one pure virtual method
class Figure
{
private:
    string name;
public:
	Figure(string name) : name(name)
	{ }

	string GetName() const { return name; }

	virtual void Show() const
	{
		cout << "Name: " << name << endl;
	}

	// pure virtual method
	virtual float GetSquare() const = 0;
	virtual float GetPerimeter() const = 0;
};

class Square : public Figure
{
protected:
	long length;
public:
	Square(string name, long l) : Figure(name), length(l)
	{ }

	float GetSquare() const override
	{
		return length * 2;
	}
	float GetPerimeter() const override
	{
		return length * 4;
	}

	void Show() const override
	{
		Figure::Show();
		cout << "Size: " << length << "x" << length << endl;
	}
};

class Rectangle : public Square
{
private:
	long width;
public:
	Rectangle(string name, long l, long w) : Square(name, l), width(w)
	{ }

	float GetSquare() const override
	{
		return width * length;
	}
	float GetPerimeter() const override
	{
		return width * 2 + length * 2;
	}
	void Show() const override
	{
		Figure::Show();
		cout << "Size: " << width << "x" << length << endl;
	}
};

void ClearArr(Figure** arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete arr[i];
	}
}

int main()
{
	const int size = 3;
	Figure* arr[size] =
	{
		//new Figure("Some figure"), // cannot create an instance of an abstract class
		new Square("Square", 15),
		new Rectangle("Rectangle", 3, 10)
	};

	Figure* figure = new Rectangle("Rectangle", 56, 100);

	for (size_t i = 0; i < size; i++)
	{
		arr[i]->Show();
		cout << "S: " << arr[i]->GetSquare() << " cm^2" << endl;
		cout << "P: " << arr[i]->GetPerimeter() << " cm" << endl;
	}

	ClearArr(arr, size);
}
