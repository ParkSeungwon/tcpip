//server exe
#include <iostream>
#include <string>
#include "tcpip.h"
using namespace std;

int main()
{
	string s;
	Server sv;
	while(s != "end") {
		s = sv.recv();
		cout << s << endl;
		s += " : " + to_string(s.size());
		sv.send(s);
	}
}

