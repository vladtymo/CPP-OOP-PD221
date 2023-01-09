#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// --------------- Resources ---------------
class Resource
{
private:
    const int value;
protected:
    const int depth;
public:
    Resource(int value, int depth) : value(value), depth(depth) { }

    virtual void ShowInfo() const
    {
        cout << "Resource in the depth of " << depth << "m with value of " << value << endl;
    }
    int GetValue() const { return value; }
    virtual void Mine() = 0;
};

class Wood : public Resource
{
public:
    Wood() : Resource(25, 3) {}

    void ShowInfo() const
    {
        cout << "This is Wood. ";
        Resource::ShowInfo();
    }

    void Mine() override
    {
        cout << "Click button [W] " << depth << " times to mine this resource\n";
        
        for (int count = 0; count < depth; )
        {
            int code = _getch();
        
            if (code == 'w' || code == 'W')
            {
                ++count;
            }
        }
    }
};
class Gold : public Resource
{
public:
    Gold() : Resource(48, 12) { }

    void ShowInfo() const
    {
        cout << "This is Gold. ";
        Resource::ShowInfo();
    }

    void Mine() override
    {
        cout << "Click button [G] " << depth << " times to mine this resource\n";

        for (int count = 0; count < depth; )
        {
            int code = _getch();

            if (code == 'g' || code == 'G')
            {
                ++count;
            }
        }
    }
};
class Diamonds : public Resource
{
public:
    Diamonds() : Resource(82, 27) { }

    void ShowInfo() const
    {
        cout << "This is Diamonds. ";
        Resource::ShowInfo();
    }

    void Mine() override
    {
        cout << "Click button [D] " << depth << " times to mine this resource\n";

        for (int count = 0; count < depth; )
        {
            int code = _getch();

            if (code == 'd' || code == 'D')
            {
                ++count;
            }
        }
    }
};

// ------------------------------------------
class Player
{
private:
    string name;
    int score;

public:
    Player(string name) : name(name), score(0) { }

    void AddScore(int value)
    {
        if (value > 0)
            score += value;
    }
    void ShowStatus() const
    {
        cout << "Player " << name << " has " << score << " score!\n";
    }
};

class Map
{
    int size;
    Resource** resources;

    Player player;

public:
    Map(string name) : player(name)
    {
        size = 5;
        resources = new Resource * [size]
        {
            new Wood(),
            new Gold(),
            new Wood(),
            new Diamonds(),
            new Wood()
        };
    }
    ~Map()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete resources[i];
        }
        delete[] resources;
    }

    void Start()
    {
        for (size_t i = 0; i < size; i++)
        {
            resources[i]->ShowInfo();
            resources[i]->Mine();
            player.AddScore(resources[i]->GetValue());

            player.ShowStatus();
        }
    }
};

int main()
{
    Map map("Vlad");
    map.Start();
}