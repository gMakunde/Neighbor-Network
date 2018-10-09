#include <iostream>
#include <string>
using namespace std;
#include "Neighbor_Network.h"

int main() {
  string SignOrSearch;
	cout<<  "Hello, Welcome to the Neighbor Network! Would you like to Sign Up or Search for an item?";
	getline(cin, SignOrSearch);
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
