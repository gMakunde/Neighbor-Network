#include <iostream>
#include <fstream>
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
  if (dorm =="baldwin"|| dorm == "baldwin hall" || dorm == "bh"){
    return "baldwin";
  }
  if (dorm =="cummings"|| dorm == "cummings hall" || "cummings house" || dorm == "ch"){
    return "cummings";
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
    user u;
    cout << "Enter Name: ";
    getline(cin, u.name);

    cout << "Enter Residence Hall: ";
    getline(cin, u.residence);
    u.residence = standard_dorm_name(u.residence);

    cout << "Enter Email: ";
    getline(cin, u.email);

    cout << "Enter Number";
    getline(cin, u.number);

    cout << "How many items are you willing to give?";
    cin >> u.items_len;

    string items[u.items_len];
    string item;

    for (int i=0; i<u.items_len; i++){
      cout << "Enter Item " << i+1 << ": "<< endl;
      cin >> ws;
      getline(cin, item);
      transform(item.begin(), item.end(), item.begin(), ::tolower);
      items[i] = item;
    }
    string e = u.email;
    string file = e.append(".txt");

    ofstream user_info;
    user_info.open(file.c_str());
    user_info << u.name << ' ' << u.residence << ' ' << u.email << ' ' << u.number << ' ' << u.items_len << ' ' << endl;
    for (int i=0; i<u.items_len; i++){
      user_info << items[i] << ' ';
    }
    user_info.close();
    
}

void search(){

}
