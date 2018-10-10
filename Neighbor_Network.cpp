#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "Neighbor_Network.h"


string standard_dorm_name(string dorm){
  transform(dorm.begin(), dorm.end(), dorm.begin(), ::tolower);

  if (dorm == "harper tubman" ||  dorm == "harper" || dorm == "tubman" || dorm == "harper-tubman" || dorm == "ht"){
      return "harper";
    }
  if (dorm == "oc" ||  dorm == "o'connell hall" || dorm == "oconnell hall" || dorm == "o'connell" || dorm == "o-connell" ){
    return "o'connell";
  }
  if (dorm == "rawlings" || dorm == "rawlings hall" || dorm == "rawlings-hall" || dorm == "rh"){
    return "rawlings";
  }
  if (dorm =="blount"|| dorm == "blount towers" || dorm == "towers" || dorm == "blount-towers" || dorm == "bt"){
    return "blount";
  }
  if (dorm == "thurgood marshall apartments" || dorm == "thurgood marshall" || dorm == "thurgood"  || dorm == "tmac" || dorm == "apartments" || dorm == "thurgood-marshall-apartments" || dorm == "tma"){
    return "thurgood";
  }
  if (dorm == "marble hall" || dorm == "marble" || dorm == "marble-hall" || dorm == "mh"){
    return "marble";
  }
  if (dorm == "morgan view"  || dorm == "mv" || dorm == "morgan" || dorm == "view" || dorm == "morgan-view"){
    return "morgan view";
  }
  if (dorm == "cw" || dorm == "campus wide" || dorm == "campus-wide" || dorm == "campus" || dorm == "wide" ){
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
    getline(cin, name);

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
    
