#include <iostream>
#include <string>
using namespace std;
#include "Neighbor_Network.h"

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

void sign_up(){
    string name;
    string residence_halls;
    string email;
    string phone_number;
    string item;
    int number_of_items;
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Residence Hall: ";
    cin >> residence_halls;
    residence_halls = standard_dorm_name(residence_halls);

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Number";
    cin >> phone_number;
   
    cout << "How many items are you willing to give?";
    cin >> number_of_items;
    
    string items[number_of_items];
    for (int i; i<number_of_items; i++){
      cout << "Enter Item: " << endl;
      cin >> item;
      items[i] = item;
    }

}
