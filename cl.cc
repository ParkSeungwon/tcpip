//client exe
#include "tcpip.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	Client cl;
	while(s != "end") {
		cin >> s;
		cl.send(s);
		cout << "here" << endl;
		cout << cl.recv();
	}
}

