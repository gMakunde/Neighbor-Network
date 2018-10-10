#ifndef USER_H
#define USER_H
using namespace std;
#include <string>

string standard_dorm_name(string);
void sign_up();
void search();

struct user {
  string residence;
  string name;
  string email;
  string number;
  int items_len;
  
};



#endif
