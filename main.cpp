#include <iostream>
#include <string>
using namespace std;

struct Info {
    string residence;
    string name;
    string email;
    string number;
    string item;
};


int main() {
    string s;
    const int SIZE = 9;
    string res_halls[SIZE] = {"Baldwin Hall","Blount Towers", "Cummings House", "Harper-Tubman House", "Marble Hall Gardens Apartments", "O'Connell Hall", "Rawlings Hall", "Thurgood Marshall Apartments", "Morgan View"};
    
    cout << "Hello, Welcome to the Neighbor Network! Would you like to Sign Up or Search for an item?" << endl;
    cin >> ws;
    getline(cin, s);


    Info user;
    
    if (s == "sign up" || s == "Sign Up" || s == "Sign up" || s == "sign Up"){
        cout << "Enter Residence Hall: " << endl;
        cin.ignore();
        getline(cin, user.residence);

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, user.name);

        cout << "Enter Email: ";
        cin.ignore();
        getline(cin, user.email);

        cout << "Enter Number";
        cin.ignore();
        getline(cin, user.number);

        cout << "Enter Item: ";
        cin.ignore();
        getline(cin, user.item);
    }

    // if (s == "Search" || s == "search"){

    // }



return 0;
}
