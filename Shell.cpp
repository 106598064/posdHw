#include <gtest/gtest.h>
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "exp.h"


#include <sstream>

using namespace std;

string& lol(string &s);

int main( int argc , char **argv ) {


	do {
		cout << "?-";
		string input;
		getline(cin, input);
		if (lol(input) == "halt.")
			break;
		if (lol(input) == "")
			continue;
		Scanner s(input);
		Parser p(s);
		try{


			p.buildExpression();
			string result = p.getExpressionTree()->getResult() + '.';
			cout << result << endl;
		} catch (std::string & msg) {
			cout << msg << endl;
		}
	} while(true);
    return 0;


}

string& lol(string &s) {
    if (s.empty()) {
         return s;
    }
    int index = 0;
    string str="";


    
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] != ' '){
            index = i;
            str = str + s[i];
        }
    }
    s = str;
    return s;
}
