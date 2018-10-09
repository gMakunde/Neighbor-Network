#include <iostream>
#include <string>
using namespace std;
#include "Neighbor_Network.h"

int main() {
  const int SIZE = 9;
  string res_halls[SIZE] = {"Baldwin Hall","Blount Towers", "Cummings House", "Harper-Tubman House", "Marble Hall Gardens Apartments", "O'Connell Hall", "Rawlings Hall", "Thurgood Marshall Apartments", "Morgan View"};

  string SignOrSearch;
	cout<<  "Hello, Welcome to the Neighbor Network! Would you like to Sign Up or Search for an item?";
	cin >> SignOrSearch;
  Info user;
  if (SignOrSearch == "sign up" || SignOrSearch == "Sign Up" || SignOrSearch == "Sign up" || SignOrSearch == "sign Up"){
    sign_up();
  } 
  else if (SignOrSearch == "Search" || SignOrSearch == "search"){
    string dorm;
    cout<< "Enter The dorm you would like to search or enter Campus-wide";
    cin >> dorm;
    dorm = standard_dorm_name(dorm);
    string item;
    cout << "enter the name of the item you are searching for";
    cin >> item;

  }



return 0;
}
