//server exe
#include <iostream>
#include <string>
#include <unistd.h>
#include "tcpip.h"
using namespace std;

int main()
{
	string s;
here:
	Server sv;
	if(fork() == 0) {
		while(s != "end") {
			s = sv.recv();
			cout << s << endl;
			s += " : " + to_string(s.size());
			sv.send(s);
		}
	} else goto here;
}

