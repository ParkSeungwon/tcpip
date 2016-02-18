//server exe
#include <iostream>
#include <string>
#include <unistd.h>
#include "tcpip.h"
using namespace std;

string procedure(string s)
{
	return s += " : " + to_string(s.size());
}

int main()
{
	Server sv;
	sv.start(procedure);
}

