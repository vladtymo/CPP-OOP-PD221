#include <iostream>
#include <string>
using namespace std;

class invalid_login : public std::logic_error
{
public:
    invalid_login() : logic_error("Login is invalid") { }
    invalid_login(string message) : logic_error(message.c_str()) { }
};

class invalid_password : public std::logic_error
{
public:
    invalid_password() : logic_error("Password is invalid") { }
    invalid_password(string message) : logic_error(message.c_str()) { }
};

class Account
{
    string login = "super123";
    string password = "Qwerty";
    bool isLoggedIn = false;

public:
    void Login(string login, string password)
    {
        if (login != this->login) throw invalid_login();
        if (password != this->password) throw invalid_password();

        cout << "User is logged in successfully!\n";
        isLoggedIn = true;
    }
    void Logout()
    {
        cout << "User is logged out successfully!\n";
        isLoggedIn = false;
    }
    void ShowStatus() const
    {
        cout << "User status: " << (isLoggedIn ? "Logged In" : "Logged Out") << endl;
    }
};

int main()
{
    Account account;

    try
    {
        account.Login("super123", "1Qwerty");
    }
    catch (const invalid_login& ex)
    {
        cout << "Error with login!\n";
        cout << ex.what() << endl;
    }
    catch (const invalid_password& ex)
    {
        cout << "Error with password!\n";
        cout << ex.what() << endl;
    }

    account.ShowStatus();
    account.Logout();
}