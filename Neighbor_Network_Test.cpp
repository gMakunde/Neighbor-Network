#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "Neighbor_Network.h"

int main() {
  string SignOrSearch;
	cout<<  "Hello, Welcome to the Neighbor Network! Would you like to Sign Up or Search for an item? ";
	getline(cin, SignOrSearch);
  transform(SignOrSearch.begin(), SignOrSearch.end(), SignOrSearch.begin(), ::tolower);
  if (SignOrSearch == "sign up"){
    sign_up();
    string yesOrno;
    cout << "Thanks for Signing up with the Neighbor Network!" << endl;
    cout << "Would you Like to search the Neighbor Network? (y/n) ";
    cin >> yesOrno;
    transform(yesOrno.begin(), yesOrno.end(), yesOrno.begin(), ::tolower);
    if (yesOrno == "yes" || yesOrno == "y"){
      SignOrSearch = "search";
    }
    else{
      SignOrSearch = "end";
    }
  } 
  if (SignOrSearch == "search"){
    string dorm;
    cout<< "Enter The dorm you would like to search or enter Campus-wide? ";
    cin >> dorm;
    dorm = standard_dorm_name(dorm);
    string item;
    cout << "enter the name of the item you are searching for ";
    getline(cin, item);
    search(dorm, item);

  }
  if (SignOrSearch == "end"){
    cout << "okay, have a great day!" << endl;
  }
  else{
    cout << "Sorry that is not a valid choice :/. Please Try again" << endl;
    main();
  }



return 0;
}
