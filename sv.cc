//server exe
#include <string>
#include <iostream>
#include "tcpip.h"
using namespace std;

class F 
{

public:
	string str {"[from functor]"};
	string operator()(string s) {
		return str + s + " : " + to_string(s.size());
	}
};

int main()
{
	auto f = [](string s) {
		string str = "[from server] ";
		str += s + " : " + to_string(s.size());
		return str;
	};

	Server sv;
	sv.start(F());
}

