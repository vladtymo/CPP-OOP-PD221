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
    }
};

int main()
{
    SmartPhone phone("iPhone 6S Plus", "Gray", 64);

    phone.Show();
    phone.ShowApps();
}
