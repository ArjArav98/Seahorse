#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TokensTable {

	vector<string> tokenKeywords;
	vector<string> tokenKeywordClasses;

	public:
	TokensTable() {
		addTokenKeywords("if"		,"keyword");
		addTokenKeywords("else"		,"keyword");
		addTokenKeywords("while"	,"keyword");
		addTokenKeywords("for"		,"keyword");
		addTokenKeywords("class"	,"keyword");
		addTokenKeywords("return"	,"keyword");
		addTokenKeywords("int"		,"datatype");
		addTokenKeywords("void"		,"datatype");
	}

	void addTokenKeywords(string tokenKeyword, string tokenKeywordClass) {
		tokenKeywords.push_back(tokenKeyword);
		tokenKeywordClasses.push_back(tokenKeywordClass);
	}

	bool search(string tokenKeyword) {
		
		int size = tokenKeywords.size();
		for(int iter=0; iter<size; iter++) {
			if(tokenKeywords[iter] == tokenKeyword) return true;
		}

		return false;
	}

};

int main() {

	return 0;
}
