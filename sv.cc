//server exe
#include <string>
#include "tcpip.h"
using namespace std;

class F 
{
	public:
		string operator()(string s) {
			return s;
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
	sv.start(f);
}

