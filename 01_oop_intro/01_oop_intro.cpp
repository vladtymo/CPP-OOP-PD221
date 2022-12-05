// 01_oop_intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// -=-=-=-=-=-=-=- Procedural Programming -=-=-=-=-=-=-=-

//struct FootballPlayer
//{
//    string name;
//    float height;
//    int games;
//    int goals;
//    float averageGoals;
//};
//
//void ShowPlayer(const FootballPlayer& player)
//{
//    cout << "---------- Player ----------\n";
//    cout << "Name: " << player.name << endl;
//    cout << "Height: " << player.height << "cm" << endl;
//    cout << "Games: " << player.games << endl;
//    cout << "Goals: " << player.goals << endl;
//    cout << "Koef: " << player.averageGoals << endl;
//}
//void SetPlayerKoef(FootballPlayer& player)
//{
//    player.averageGoals = (float)player.goals / player.games;
//}
//void InitPlayer(FootballPlayer& player)
//{
//    cout << "\tEnter new player data \n";
//    cout << "Enter name: ";
//    cin >> player.name;
//    cout << "Enter height: ";
//    cin >> player.height;
//    cout << "Enter games: ";
//    cin >> player.games;
//    cout << "Enter goals: ";
//    cin >> player.goals;
//
//    SetPlayerKoef(player);
//}
//void AddGame(FootballPlayer& player, int goals = 0)
//{
//    player.games++;
//    player.goals += goals;
//
//    SetPlayerKoef(player);
//}

// -=-=-=-=-=-=-=- Object-Oriented Programming (OOP) -=-=-=-=-=-=-=-
class Player
{
private: // can access only from the class (default)
    // properties
    string name;
    float height;
    int games;
    int goals;
    float averageGoals;

    // private method
    void SetKoef()
    {
        averageGoals = (float)goals / games;
    }

public: // can access from everywhere
   
    // behaviour / methods
    // public interface

    void Show()
    {
        cout << "---------- Player ----------\n";
        cout << "Name: " << name << endl;
        cout << "Height: " << height << "cm" << endl;
        cout << "Games: " << games << endl;
        cout << "Goals: " << goals << endl;
        cout << "Koef: " << averageGoals << endl;
    }
    void Init()
    {
        cout << "\tEnter new player data \n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter games: ";
        cin >> games;
        cout << "Enter goals: ";
        cin >> goals;

        SetKoef();
    }
    void AddGame(int goals = 0)
    {
        // this - pointer to this class object
        //(*this).property;
        //this->property;

        ++games;
        this->goals += goals;

        SetKoef();
    }
};

int main()
{
    /*FootballPlayer pl1;

    InitPlayer(pl1);
    ShowPlayer(pl1);

    AddGame(pl1, 3);
    AddGame(pl1);
    AddGame(pl1, 2);
    AddGame(pl1);

    ShowPlayer(pl1);*/

    Player pl2;

    pl2.Init(); // set koef automatically

    //pl2.SetKoef(); // cannot access
    
    pl2.Show();

    pl2.AddGame(3);
    pl2.AddGame();
    pl2.AddGame(6);

    //pl2.games = -100;

    pl2.Show();
}
