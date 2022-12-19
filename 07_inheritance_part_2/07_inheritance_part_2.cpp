#include <iostream>
#include <string>
using namespace std;

class PublicTransport
{
private:
    string model;
    int totalPlaces;
    int freePlaces;
    string color;
protected:
    float currentSpeed;

public:
    PublicTransport(string m, int p, string c)
        : model(m), currentSpeed(0), totalPlaces(p), freePlaces(p), color(c)
    { }

    void ShowShortInfo() const
    {
        cout << "Transport: " << model << ": " << color << "\n";
    }
    void ShowInfo() const
    {
        cout << "---------- " << model << " ----------\n";
        cout << "Speed: " << currentSpeed << "km/h\n";
        cout << "Free Places: " << freePlaces << " of " << totalPlaces << "\n";
        cout << "Color: " << color << "\n";
    }

    void Stop()
    {
        currentSpeed = 0;
        cout << "Transport was stoped!\n";
    }

    void Drive()
    {
        currentSpeed = 40;
        cout << "Transport is driving with speed of " << currentSpeed << "km/h\n";
    }

    void AddPassanger()
    {
        if (freePlaces > 0)
        {
            --freePlaces;
            cout << "Passanger added!\n";
        }
        else
        {
            cout << "No free places exist!\n";
        }
    }

    void RemovePassanger()
    {
        if (freePlaces < totalPlaces)
        {
            ++freePlaces;
            cout << "Passanger got out!\n";
        }
        else
        {
            cout << "No passengers!\n";
        }
    }
};

class Taxi : public PublicTransport
{
private:
    string category;
    bool isFree;

public:
    Taxi(string m, int p, string c, string category) 
        : PublicTransport(m, p, c), category(category), isFree(true)
    {}

    void Drive()
    {
        currentSpeed = 60;
        cout << "Taxi is driving with speed of " << currentSpeed << "km/h\n";
    }

    void ConfirmOrder(int passengers)
    {
        if (isFree)
        {
            isFree = false;
            cout << "Order was confirmed!\n";
            for (size_t i = 0; i < passengers; i++)
            {
                this->AddPassanger();
            }
        }
        else
            cout << "Taxi currently is busy! Please, order another one.\n";
    }

    void ShowInfo() const
    {
        PublicTransport::ShowInfo();
        cout << "Category: " << category << endl;
        cout << "Status: " << (isFree ? "Free" : "Busy") << endl;
    }
};

class Train : public PublicTransport
{
private:
    int wagons;

public:
    Train(string m, int p, string c, int w)
        : PublicTransport(m, p, c), wagons(w)
    { }

    void ShowInfo() const
    {
        PublicTransport::ShowInfo();
        cout << "Wagons: " << wagons << endl;
    }

    void Drive()
    {
        currentSpeed = 90;
        cout << "Ttain is driving with speed of " << currentSpeed << "km/h\n";
    }

    void UnhitchWagon()
    {
        if (wagons > 0)
        {
            --wagons;
            cout << "The last wagon was unhitched!\n";
        }
        else
            cout << "No wagons to unhitch!\n";
    }
};

class Bicycle
{

};

void TestDrive(PublicTransport transport)
{
    transport.ShowShortInfo();
    transport.Drive();
    transport.Stop();
}

int main()
{
    PublicTransport transport("Bus", 23, "Red");
    transport.ShowInfo();
    transport.Drive();
    transport.AddPassanger();
    transport.RemovePassanger();
    transport.Stop();

    Taxi taxi("Toyota", 5, "Gray", "Econom");
    taxi.ShowInfo();
    taxi.ConfirmOrder(6);
    taxi.Drive();

    Train train("Ukrtrain", 480, "Blue", 12);
    train.ShowInfo();
    train.UnhitchWagon();
    train.Drive();

    PublicTransport tr2 = taxi;
    tr2 = train;
    tr2 = transport;

    cout << "\tTest Drive:\n";
    TestDrive(transport);
    TestDrive(taxi);
    TestDrive(train);

    Bicycle bicycle;

    // garage
    PublicTransport garage[3]
    {
        transport,
        taxi,
        train
        //bicycle // dows not inherited PublicTransport class
    };

    cout << "\tGarage:\n";
    for (size_t i = 0; i < 3; i++)
        garage[i].ShowShortInfo();
}