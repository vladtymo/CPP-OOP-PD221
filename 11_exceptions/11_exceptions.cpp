#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Converter
{
	const static int KILO = 1000;
public:
	// -1: Overflow 
	// -2: Invalid value
	static int ToMetters(int kilometers)
	{
		if ((double)kilometers * KILO > INT32_MAX)
		{
			//return -1;
			throw exception("Overflow error!");
		}
		if (kilometers < 0)
		{
			//cout << "Invalid value!\n";
			//return -2;
			throw exception(("Invalid value (" + to_string(kilometers) + ")!").data());
		}

		double result = kilometers * KILO;
		return result;
	}
	static void ShowTime(long seconds)
	{
		cout << "HH:MM:SS" << endl;
	}
};

int main()
{
	cout << "Enter kilometers to convert: ";
	int m = 0;
	cin >> m;

	//int result = Converter::ToMetters(m);

	/*switch (result)
	{
	case -1: cout << "Overflow error!\n"; break;
	case -2: cout << "Invalid value!\n"; break;
	default:
		cout << "Metters: " << result << "m\n";
		break;
	}*/

	try
	{
		Converter::ToMetters(34);

		cout << "Metters: " << Converter::ToMetters(m) << "m\n";
	}
	catch (const std::exception& ex)
	{
		// обробка виключної ситуації
		cout << "Message: " << ex.what() << endl;
	}
	
	cout << "Continue...\n";

	do
	{
		cout << "Enter value to convert: ";
		cin.clear();
		int value; cin >> value;

		try
		{
			cout << "Metters: " << Converter::ToMetters(value) << "m\n";
			break;
		}
		catch (const std::exception& ex)
		{
			// обробка виключної ситуації
			cout << "Incorrect data. Please input again!";
		}

	} while (true);
}
