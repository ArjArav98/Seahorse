#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Preprocessor {

	public:
	static void includeLibraries(string filename) {

		

	}

	static string extractLibraryName(string str) {

		int length = str.length();
		string library = "";
		int flag = 0;

		for(int iter=0; iter<length; iter++) {
			if(str[iter] == '\"') flag = (flag - 1) * -1;
			else if(flag == 1) library += str[iter];
			else;
		}

		return library;

	}

};
