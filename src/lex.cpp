#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

/* Represents a table which contains tokens and their classes. */
class TokensTable {

	vector<string> keywords;
	vector<string> keywordClasses;

	public:
	TokensTable() {
		addRow("if"	,"keyword");
		addRow("else"	,"keyword");
		addRow("while"	,"keyword");
		addRow("for"	,"keyword");
		addRow("class"	,"keyword");
		addRow("return"	,"keyword");
		addRow("int"	,"datatype");
		addRow("void"	,"datatype");
		addRow("double"	,"datatype");
		addRow(""	,"whitespace");
	}

	private:
	void addRow(string keyword, string keywordClass) {
		keywords.push_back(keyword);
		keywordClasses.push_back(keywordClass);
	}

	public:
	bool contains(string keyword) {
		int size = keywords.size();
		for(int iter=0; iter<size; iter++) {
			if(keywords[iter] == keyword) return true;
		}

		return false;
	}

};

/* Represents a TokensParser class which extracts tokens from given inputs. */
class TokensParser {

	public:
	static vector<string> extractTokensFromFile(string filename) {
		ifstream file;
		file.open(filename);

		vector<string> tokens;

		while(!file.eof()) {
			string token;
			file>>token;
			tokens.push_back(token);
		}

		return tokens;
	}

};

/* Represents a class which verifies if the tokens given in are present in the table. */
class TokensValidator {

	public:
	static bool allTokensAreValid(vector<string>* tokens, TokensTable* tokensTable) {
		int noOfTokens = (*tokens).size();

		for(int iter=0; iter<noOfTokens; iter++) {
			cout<<"The current token is '"<<(*tokens)[iter]<<"'\n";
			if((*tokensTable).contains((*tokens)[iter]));
			else return false;
		}

		return true;
	}

};

int main() {

	TokensTable table;
	vector<string> tokens = TokensParser::extractTokensFromFile("hello.txt");

	if(TokensValidator::allTokensAreValid(&tokens,&table)) cout<<"Yes, all tokens are valid!"<<endl;
	else cout<<"No, all tokens are not valid!"<<endl;

	return 0;
}
