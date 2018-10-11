#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
using namespace std;
#include <experimental/filesystem>
#include "Neighbor_Network.h"
// Creates a standard dorm name to make help make search more accurate
string standard_dorm_name(string dorm) {
	//makes everything lowercase to keep standard
	transform(dorm.begin(), dorm.end(), dorm.begin(), ::tolower);

	if (dorm == "harper tubman" || dorm == "harper" || dorm == "tubman" || dorm == "harper-tubman" || dorm == "ht") {
		return "Harper-Tubman House";
	}
	else if (dorm == "oc" || dorm == "o'connell hall" || dorm == "oconnell hall" || dorm == "o'connell" || dorm == "o-connell") {
		return "O'connell Hall";
	}
	else if (dorm == "rawlings" || dorm == "rawlings hall" || dorm == "rawlings-hall" || dorm == "rh") {
		return "Rawlings Hall";
	}
	else if (dorm == "blount" || dorm == "blount towers" || dorm == "towers" || dorm == "blount-towers" || dorm == "bt") {
		return "Blount Towers";
	}
	else if (dorm == "baldwin" || dorm == "baldwin hall" || dorm == "bh") {
		return "Baldwin Hall";
	}
	else if (dorm == "cummings" || dorm == "cummings hall" || dorm == "cummings house" || dorm == "ch") {
		return "Cummings House";
	}
	else if (dorm == "thurgood marshall apartments" || dorm == "thurgood marshall" || dorm == "thurgood" || dorm == "tmac" || dorm == "apartments" || dorm == "thurgood-marshall-apartments" || dorm == "tma") {
		return "Thurgood Marshall Apartments";
	}
	else if (dorm == "marble hall" || dorm == "marble" || dorm == "marble-hall" || dorm == "mh") {
		return "Marble Hall";
	}
	else if (dorm == "morgan view" || dorm == "mv" || dorm == "morgan" || dorm == "view" || dorm == "morgan-view") {
		return "Morgan View";
	}
	else if (dorm == "cw" || dorm == "campus wide" || dorm == "campus-wide" || dorm == "campus" || dorm == "wide") {
		return "campus wide";
	}
	cout << "That is not a Valid dorm name please try again. ";
	cin >> dorm;
	return standard_dorm_name(dorm);
}
//function used where users will sign up
void sign_up() {
	user u;
	cout << "Enter Name: ";
	getline(cin, u.name);

	cout << "Enter Residence Hall: ";
	getline(cin, u.residence);
	u.residence = standard_dorm_name(u.residence);

	cout << "Enter Email: ";
	getline(cin, u.email);

	cout << "Enter Number: ";
	getline(cin, u.number);

	cout << "How many items are you willing to give? ";
	cin >> u.items_len;

	string items[u.items_len];

	for (int i = 0; i < u.items_len; i++) {
		cout << "Enter Item " << i + 1 << ": " << endl;
		cin >> ws;
		getline(cin, u.items);
		//makes everything lowercase to keep standard
		transform(u.items.begin(), u.items.end(), u.items.begin(), ::tolower);
		items[i] = u.items;
	}
	string e = u.email;
	//all text files will be named after the users email address
	string file = e.append(".txt");

	u.items = "";
	for (int i = 0; i < u.items_len; i++) {
		u.items += items[i];
	}
	// writing user info into a text file that will be saved in this directory
	ofstream user_info;
	user_info.open(file.c_str());
	user_info << u.residence << endl << u.items << endl << u.name << endl << u.number << endl << u.email << endl;
	user_info.close();

}
// function used to get the path of the current directory
string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}
// function used to convert "directory_entry " value type to std::string value type
void GetFilenames(vector<string> &FileNames) {
	experimental::filesystem::path directory(ExePath());
	experimental::filesystem::directory_iterator iter(directory), end;

	for (; iter != end; ++iter) {
		if (iter->path().extension() == ".txt") {
			FileNames.push_back(iter->path().filename().string());
		}
	}
}
void search(string dorm, string item) {
	// this vector will have the names of all text files in this directory
	vector <string> FileNames;
	GetFilenames(FileNames);
	// all matches will be stored in this vector
	vector<string> matches;
	user u;
	for (int i = 0; i < FileNames.size(); i++) {
		//reading in all text files in vector and saving them to struct variables
		ifstream myfile;
		myfile.open(FileNames[i].c_str());
		if (myfile.is_open()){
			string line;
			getline(myfile, line);
				u.residence = line;
			getline(myfile, line);
				u.items = line;
			getline(myfile, line);
				u.name = line;
			getline(myfile, line);
				u.number = line;
			getline(myfile, line);
				u.email = line;
			myfile.close();
		}
		// if the dorm matches and the items match, add the users info to the matches vector
		if (dorm == u.residence && u.items.find(item) != string::npos) {
			matches.push_back(u.name);
			matches.push_back(u.residence);
			matches.push_back(u.number);
			matches.push_back(u.email);
		}
		// if the items match, add the users info to the matches vector
		else if (dorm == "campus wide" && u.items.find(item) != string::npos) {
			matches.push_back(u.name);
			matches.push_back(u.residence);
			matches.push_back(u.number);
			matches.push_back(u.email);
		}
	}
	int size = matches.size();
  if (size > 0){
		// Size of vector should be a multiple of four
		int i1 = 0;
		int i2 = 1;
		int i3 = 2;
		int i4 = 3;
		int z = 1;
		cout << "We found you " << size / 4 << " matches!" << endl;
		// while size is greater than 0 cout matches to the screen
		while (size > 0) {
			cout << "Match " << z << ": " << endl;
			cout << matches[i1] << " who lives in " << matches[i2] << " has " << item << endl;
			cout << "You can call/text them at " << matches[i3] << " or email them at " << matches[i4] << endl;
			cout << " " << endl;
			z++;
			// user info comes in bunches of 4, the next user is the next 4 indecies
			i1 += 4;
			i2 += 4;
			i3 += 4;
			i4 += 4;
			size -= 4;
		}
	}
	else {
		cout << "Sorry we could not find a match :(" << endl;
	}
	cout << "Thanks for using the Neighbor Network!" << endl;
}
