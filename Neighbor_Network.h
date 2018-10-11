#ifndef USER_H
#define USER_H
using namespace std;
#include <string>
#include <vector>

string standard_dorm_name(string);
void sign_up();
void search(string, string);
string ExePath();
void GetFilenames(vector<string>&);

struct user {
	string residence;
	string name;
	string email;
	string number;
	string items;
	int items_len;

};



#endif
