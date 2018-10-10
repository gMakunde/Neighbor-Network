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
    cout << "Thanks for signing up with the Neighbor Network!" << endl;
    cout << "Would you like to search the Neighbor Network? (y/n) ";
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
    cout<< "Enter the dorm you would like to search or enter Campus-wide? ";
    cin >> dorm;
    dorm = standard_dorm_name(dorm);
    string item;
    cout << "Enter the name of the item you are searching for " << endl;
    cin >> ws;
    getline(cin, item);
    search(dorm, item);

  }
  if (SignOrSearch == "end"){
    cout << "Okay, have a great day!" << endl;
  }
  if (SignOrSearch != "end" || SignOrSearch != "search" || SignOrSearch != "sign up"){
    SignOrSearch = "wrong";
  }
  else if (SignOrSearch == "wrong"){
    cout << "Sorry that is not a valid choice :/. Please try again" << endl;
    main();
  }



return 0;
}

