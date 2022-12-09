#include <iostream>
using namespace std;

class Auto
{
private:
    string model;
    float speed;
    int maxSpeed;
    string color;
    int year;

public:
    // constructor - invoke automatically when class instance is creating
    Auto() // default constructor
    {
        model = "";
        speed = 0;
        maxSpeed = 0;
        color = "";
        year = 0;
    }
    // parametrized constructors
    Auto(string model, string color, int year, int maxSpeed)
    {
        this->model = model;
        this->color = color;

        /*if (year < 1886 )
            this->year = 1886 ;
        else 
            this->year = year;*/
        this->year = (year < 1886) ? 1886 : year;

        this->maxSpeed = (maxSpeed < 0) ? 0 : maxSpeed;
        this->speed = 0;
    }

    /*void Init()
    {
        model = "";
        speed = 0;
        maxSpeed = 0;
        color = "";
        year = 0;
    }*/
    /*void Init(string model, string color, int year, int maxSpeed)
    {
        this->model = model;
        this->color = color;
        this->year = year;
        this->maxSpeed = maxSpeed;
        this->speed = 0;
    }*/

    // const methods - do not modify any property of the class
    void Show() const
    {
        cout << "======== " << model << " ========\n";
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
        cout << "Speed: " << speed << " of " << maxSpeed << " km/h" << endl;
    }

    void Stop()
    {
        speed = 0;
    }

    // setter / getter
    float GetSpeed() const
    {
        //speed = -10; not allowed
        return speed;
    }
    void SetSpeed(float value)
    {
        // validation - check data if it is correct
        // 0 <= speed <= maxSpeed
        if (value >= 0 && value <= maxSpeed)
            speed = value;
        else
            cout << "Invalid speed value (" << value << ")!\n"; // exceptions
    }
};

int main()
{
    // --------------- First Instance
    Auto myAuto("Nissan", "Dark Blue", 2012, 180);  // invoke constructor
    //myAuto.Init("Nissan", "Dark Blue", 2012, 180);

    // set speed
    //myAuto.speed = -25000000;
    myAuto.SetSpeed(50.2);
    myAuto.SetSpeed(350);   // ignore
    myAuto.SetSpeed(-2300); // ignore
    myAuto.SetSpeed(-1);    // ignore
    
    // get speed
    cout << "Current speed is " << myAuto.GetSpeed() << "km/h\n";
   
    myAuto.Stop();

    myAuto.Show();

    // --------------- Second Instance
    Auto yourAuto; // invoke constructor

    yourAuto.SetSpeed(160);
    yourAuto.Show();

    Auto hisAuto = {};                                // default constructor
    Auto herAuto = { "Peugeot", "White", 2017, 190 }; // parametrized constructor
}
