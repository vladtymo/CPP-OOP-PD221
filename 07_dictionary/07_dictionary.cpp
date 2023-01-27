#include "Dictionary.h"

class Identity
{
    string login;
    string address;

public:
    Identity() { }
    Identity(string l, string a): login(l), address(a) { }

    // TODO:
    // overload [<<] operator
    // overload [==] operator
};

int main()
{
    Dictionary<string, int> collection;

    collection.Add("Ukraine", 504656384);
    collection.Add("Italy", 57375834);
    collection.Add("Poland", 1424334);

    collection.Show();

    cout << "Find: " << collection.Get("Poland") << endl;

    collection["Poland"] = 787878787;
    cout << "Find: " << collection["Poland"] << endl;

    // -------------------- User-Defined class as a Key
    Dictionary<Identity, string> users;

    users.Add(Identity("super12", "Rivne"), "Volodia");
    users.Add(Identity("blala_user", "Lviv"), "Viktor");

    //users.Show(); // need operator [<<]
}