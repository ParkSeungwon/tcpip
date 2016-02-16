//tcpip.h class definition
#include <string>
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
	Server(int port = 2001, int queue = 10);
	void set_process_func(std::string (*process_string)(std::string));

protected:
	std::string (*process_string)(std::string);
	handle_connection();
};
