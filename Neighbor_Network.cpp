#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
using namespace std;
#include <experimental/filesystem>
#include "Neighbor_Network.h"

string standard_dorm_name(string dorm) {
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
		transform(u.items.begin(), u.items.end(), u.items.begin(), ::tolower);
		items[i] = u.items;
	}
	string e = u.email;
	string file = e.append(".txt");

	u.items = "";
	for (int i = 0; i < u.items_len; i++) {
		u.items += items[i];
	}
	ofstream user_info;
	user_info.open(file.c_str());
	user_info << u.residence << endl << u.items << endl << u.name << endl << u.number << endl << u.email << endl;
	user_info.close();

}

string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

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
	vector <string> FileNames;
	GetFilenames(FileNames);
	vector<string> matches;
	user u;
	for (int i = 0; i < FileNames.size(); i++) {
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
		if (dorm == u.residence && u.items.find(item) != string::npos) {
			matches.push_back(u.name);
			matches.push_back(u.residence);
			matches.push_back(u.number);
			matches.push_back(u.email);
		}
		else if (dorm == "campus wide" && u.items.find(item) != string::npos) {
			matches.push_back(u.name);
			matches.push_back(u.residence);
			matches.push_back(u.number);
			matches.push_back(u.email);
		}
	}
	int size = matches.size();
  if (size > 0){
		int i1 = 0;
		int i2 = 1;
		int i3 = 2;
		int i4 = 3;
		int z = 1;
		cout << "We found you " << size / 4 << " matches!" << endl;
		while (size > 0) {
			cout << "Match " << z << ": " << endl;
			cout << matches[i1] << " who lives in " << matches[i2] << " has " << item << endl;
			cout << "You can call/text them at " << matches[i3] << " or email them at " << matches[i4] << endl;
			cout << " " << endl;
			z++;
			i1 += 4;
			i2 += 4;
			i3 += 4;
			i4 += 4;
			size -= 4;
		}
	}
	else {
		cout << "Sorry we could not find a match :(" << endl;
		cout << "thanks for using the Neighbor Network!" << endl;
	}
}
