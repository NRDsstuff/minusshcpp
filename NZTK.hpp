#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

// will read the entire contents of a file

string readFile(string toOpen){

	string data, toReturn;
	ifstream file;

	file.open(toOpen);

	// get the shtuff together

	while(getline(file,data)){

		toReturn = toReturn + "\n" + data;
	}

	// close it ofc

	file.close();

	return toReturn;
}

string askForInput(string question){

	string input;

	cout << question;

	getline(cin, input);

	return input;
}

string ReplaceAll(string str, const string& from, const string& to){

	// stolen but idc

	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != string::npos){

		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}

	return str;
}

class Date{

	private:
		time_t now = time(NULL);

	public:

	string getFullDate(){

		struct tm *ltime = localtime(&now);

		string FD;

		FD = to_string(ltime->tm_sec) + ":" + to_string(ltime->tm_min) + ":" + to_string(ltime->tm_hour) + " " + to_string(ltime->tm_mday + 1) + "." + to_string(ltime->tm_mon) + "." + to_string(ltime->tm_year + 1900);

		return FD;
	}

	int getSecond(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_sec;
	}
	int getMinute(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_min;
	}
	int getHour(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_hour;
	}
	int getDay(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_mday + 1;
	}
	int getMonth(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_mon;
	}
	int getYear(){


		struct tm *ltime = localtime(&now);

		return ltime->tm_year + 1900;
	}
};
