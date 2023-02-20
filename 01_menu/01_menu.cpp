#include <iostream>
#include "Colors.h"
#include <vector>
#include <conio.h>
using namespace std;

class Menu
{
private:
    vector<string> items;
	int selectedIndex = 0;

public:
	Menu()
	{
		items.assign({ "Create", "New Game", "Restart", "Exit" });
	}

	int Show()
	{
		int input = 'q';
		do
		{
			system("cls");
			SetColor(ConsoleColor::BLACK, ConsoleColor::YELLOW);
			cout << "\tMENU\n";

			for (size_t i = 0; i < items.size(); i++)
			{
				if (i == selectedIndex)
					SetColor(ConsoleColor::BLACK, ConsoleColor::WHITE);
				else
					SetColor(ConsoleColor::BLACK, ConsoleColor::GRAY);

				cout << items[i] << endl;
			}

			input = _getch();
			if (input == 224)
			{
				input = _getch();
				switch (input)
				{
				case 80:
					if (selectedIndex < items.size() - 1)
						++selectedIndex;
					break;
				case 72:
					if (selectedIndex > 0)
						--selectedIndex;
					break;
				}
			}
			else if (input == 13)
				return selectedIndex;

		} while (input != 'q');

		SetColor();
		return -1;
	}
};

int main()
{
	Menu menu;

	int choice = menu.Show();
	cout << "Your choice is " << choice << endl;
}
