#include <iostream>
#include <string>
using namespace std;
string standard_dorm_name(string);

class Info {
    string residence;
    string name;
    string email;
    string number;
    string item;
};


int main() {
  const int SIZE = 9;
  string res_halls[SIZE] = {"Baldwin Hall","Blount Towers", "Cummings House", "Harper-Tubman House", "Marble Hall Gardens Apartments", "O'Connell Hall", "Rawlings Hall", "Thurgood Marshall Apartments", "Morgan View"};
  
  string SignOrSearch;
	cout<<  "Hello, Welcome to the Neighbor Network! Would you like to Sign Up or Search for an item?";
	cin >> SignOrSearch;
  Info user;
    
  /*if (SignorSearch == "sign up" || SignorSearch == "Sign Up" || SignorSearch == "Sign up" || SignorSearch == "sign Up"){
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
  } */
  if (SignOrSearch == "Search" || SignOrSearch == "search"){
    string dorm;
  cout<< "Would You like to search in Harper Tubman, O'Connell Hall, Rawlings, Blount Towers, Thurgood Marshall Apartments, Marble Hall, Morgan View or Campus-wide?";
  cin >> dorm;
    dorm = standard_dorm_name(dorm);
  }



return 0;
}

string standard_dorm_name(string dorm){
  if (dorm == "Harper Tubman" || dorm == "Harper tubman" || dorm == "harper Tubman" || dorm == "harper Tubman" || dorm == "harper" || dorm == "tubman" || dorm == "Harper" || dorm == "Tubman"){
      return "harper";
    }
  if (dorm == "OC" || dorm == "oC" || dorm == "Oc" || dorm == "oc" || dorm == "O'Connell Hall" || dorm == "o'Connell Hall" || dorm == "O'connell Hall" || dorm == "O'Connell hall" || dorm == "o'connell Hall" || dorm == "o'connell hall" || dorm == "OConnell Hall" || dorm == "oConnell Hall" || dorm == "oconnell hall" || dorm == "Oconnell Hall" || dorm == "O'Connell" || dorm == "O'connell" || dorm == "o'connell" || dorm == "OConnell" || dorm == "Oconnell"){
    return "o'connell";
  }
  if (dorm == "Rawlings" || dorm == "rawlings" || dorm == "Rawlings Hall" || dorm == "rawlings Hall" || dorm == "Rawlings hall" || dorm == "rawlings hall"){
    return "rawlings";
  }
  if (dorm == "Blount" || dorm =="blount" || dorm == "Blount Towers" || dorm == "Blount towers" || dorm == "blount Towers" || dorm == "blount towers"){
    return "blount";
  }
  if (dorm == "Thurgood Marshall Apartments" || dorm == "Thurgood marshall Apartments" || dorm == "Thurgood Marshall apartments" || dorm == "thurgood marshall Apartments" || dorm == "Thurgood marshall apartments" || dorm == "thurgood marshall apartments" || dorm == "thurgood Marshall apartments" || dorm == "Thurgood Marshall" || dorm == "Thurgood marshall" || dorm == "thurgood Marshall" || dorm == "thurgood marshall" || dorm == "Thurgood" || dorm == "thurgood" || dorm == "TMAC" || dorm == "Tmac" || dorm == "tmac" ){
    return "thurgood";
  }
  if (dorm == "Marble Hall" || dorm == "marble Hall" || dorm == "Marble hall" || dorm == "marble hall" || dorm =="Marble" || dorm == "marble"){
    return "marble";
  }
  if (dorm == "Morgan View" || dorm == "morgan view" || dorm == "Morgan view" || dorm == "morgan View" || dorm == "mv" || dorm == "MV" || dorm == "Mv"|| dorm == "mV"){
    return "morgan view";
  }
  if (dorm == "CW" || dorm == "cw" || dorm == "Cw" || dorm == "cW" || dorm == "Campus Wide" || dorm == "Campus-Wide" || dorm == "Campus wide" || dorm == "Campus-wide" || dorm == "campus Wide" || dorm == "campus-Wide" || dorm == "campus wide" || dorm == "campus-wide"){
    return "campus wide";
  }
  cout << "That is not a Valid dorm name please try again. ";
  cin >> dorm;
  return standard_dorm_name(dorm);   
}
