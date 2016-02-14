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
		cout << s;
		sv.send(s);
	}
}

