//server exe
#include <string>
#include "tcpip.h"
using namespace std;

string procedure(string s)
{
	string str = "[from server] ";
	str += s + " : " + to_string(s.size());
	return str;
}

int main()
{
	Server sv;
	sv.start(procedure);
}

