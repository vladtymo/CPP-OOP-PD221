#include <iostream>
#include "../10_vector/Vector.h"
using namespace std;

struct Battery
{
    string model;
    int capacity;
    float voltage;

    Battery() { }
    Battery(string m, int c, float v) : model(m), capacity(c), voltage(v) { }
};
struct Display
{
    enum Type { IPS, OLED, AMOLED };
    string model;
    float diagonal;
    Type type;
    float ppi; // pixels per inch

    Display() { }
    Display(string m, float d, Type t, float p) : model(m), diagonal(d), type(t), ppi(p) { }
};
class Camera
{
private:
    string model;
    int megapixels;
    float aperture;

public:
    Camera() { }
    Camera(string model, int mp, float f) : model(model)
    {
        megapixels = mp < 1 ? 1 : mp;
        aperture = f <= 0 ? 0 : f;
    }

    int GetMP() const { return megapixels; }
    void Shoot() const
    {
        cout << "Taking a photo of " << megapixels << "MP with " << aperture << "f ...\n";
    }
    void Record() const
    {
        cout << "Recording a video of " << megapixels << "MP with " << aperture << "f ...\n";
    }
};

struct Processor
{
    string model;
    int cores;
    int frecuency;
    short technology; // nm

    Processor() { }
    Processor(string model, int c, int f, short t)
        : model(model), cores(c), frecuency(f), technology(t) { }
};

class SimCard
{
private:
    string provider;
    string number;

    const string PUK_CODE = "1234";
    string PIN_CODE = "1111";

    Vector<string> contacts;

public:
    SimCard(string provider, string number)
        : provider(provider), number(number) 
    { }

    void ShowInfo() const
    {
        cout << "Operator " << provider << ": " << number << endl;
    }

    void Activate(string PIN) const
    {
        if (PIN == PIN_CODE)
            cout << "SIM card was activated successfully!\n";
        else
            cout << "Invalid PIN code. Please try again!\n";
    }

    void ChangePIN(string newPIN, string oldPIN)
    {
        if (PIN_CODE == oldPIN)
            PIN_CODE = newPIN;
    }

    void AddContacts(initializer_list<string> list)
    {
        for (string item : list)
        {
            contacts.Push(item);
        }
    }

    void ShowContacts() const
    {
        contacts.Show("Contact list");
    }
};

class SmartPhone
{
private:
    string model;
    string color;
    int memory;

    // --------------- composition of the smart phone
    // battery
    Battery battery;
    // display
    Display display;
    // camera
    Camera camera;
    // processor
    Processor processor;
    // apps
    Vector<string> applications;

    // --------------- aggregation of the smart phone
    SimCard* simCard;

public:
    SmartPhone(string model, string color, int memory) 
        : model(model), color(color), memory(memory)
    {
        // create inner modules
        battery = Battery("Baseus", 3440, 2.7);
        display = Display("Samsung", 6.1, Display::OLED, 326);
        camera = Camera("Sony", 48, 1.8);
        processor = Processor("A12 Bionic", 4, 2400, 8);

        // install default apps
        applications.Push("Photos");
        applications.Push("Messages");
        applications.Push("Settigns");
        applications.Push("Calculator");
    }
    ~SmartPhone()
    {
        applications.Clear();
    }

    void ShowApps() const
    {
        applications.Show("Installed applications");
    }
    void Show()
    {
        cout << "Smart Phone: " << model << " " << memory << "Gb" << endl;
        cout << "Display: " << display.diagonal << "'" << endl;
        cout << "Camera: " << camera.GetMP() << "MP" << endl;
        cout << "Processor: " << processor.cores << " cores, " << processor.technology << "nm" << endl;
        if (IsSIMExists())
            simCard->ShowInfo();
        else
            cout << "No SIM Card!\n";

        cout << string(30, '-') << endl;
    }

    void MakeCall(string contact) const
    {
        if (!IsSIMExists())
        {
            cout << "SIM card is required to make a call!\n";
            return;
        }

        cout << "Calling " << contact << "...\n";
    }

    bool IsSIMExists() const
    {
        return simCard != nullptr;
    }
    void InjectSIM(SimCard* simCard)
    {
        this->simCard = simCard;
    }
    SimCard* EjectSIM()
    {
        SimCard* temp = this->simCard;
        this->simCard = nullptr;
        return temp;
    }
};

int main()
{
    SmartPhone phone("iPhone 6S Plus", "Gray", 64);

    phone.Show();
    phone.ShowApps();

    SimCard* card = new SimCard("Kyivstar", "+38098080808");

    phone.InjectSIM(card);
    phone.Show();

    phone.MakeCall("911");

    phone.EjectSIM();

    phone.MakeCall("+380 (44) 255–70–42");

    delete card;
}
