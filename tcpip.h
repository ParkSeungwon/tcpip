//tcpip.h class definition
#include <string>
#include <thread>
#include <arpa/inet.h>

class Tcpip 
{
public:
	Tcpip(int port);
	virtual ~Tcpip();
	void send(std::string s);
	std::string recv();

protected:
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;

private:
	char buffer[1024];
};

class Client : public Tcpip
{
public:
	Client(std::string ip = "127.0.0.1", int port = 2001); 
};

class Server : public Tcpip
{
public:
	Server(int port = 2001, int queue = 10, std::string e = "end");
	void start(std::string (*pf)(std::string s));

protected:
	std::string (*process_string)(std::string);
	void handle_connection();
	std::string end_string;
};
