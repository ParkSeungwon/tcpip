//client exe
#include "tcpip.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	Client cl;
	while(1) {
		cin >> s;
		cl.send(s);
		cout << cl.recv();
		if(s.compare("end") == 0) break;
	}
}

