#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Preprocessor {

	public:
	static void includeLibraries(string filename) {

		ifstream file;
		file.open(filename);

		string filetext = "";

		while(!file.eof()) {
			string str;
			getline(file,str);
			
			if(str[0] == '#') {
				string libraryfilename = extractLibraryName(str);
				ifstream libraryfile;
				libraryfile.open(libraryfilename);

				while(!libraryfile.eof()) {
					string str1;
					getline(libraryfile,str1);
					filetext += str1;

					if(libraryfile.eof());
					else filetext += "\n";
				}

				libraryfile.close();
			}
			else {
				filetext += str;
			}

			if(file.eof());
			else filetext += "\n";
		}

		file.close();

		ofstream file1;
		file1.open("hello.txt");
		file1<<filetext;
		file1.close();

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

int main() {

Preprocessor::includeLibraries("hello.txt");
	return 0;
}
