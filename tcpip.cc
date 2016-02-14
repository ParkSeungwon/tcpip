//tcpip.cc class 구현부
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "tcpip.h"
using namespace std;

Tcpip::Tcpip(int port) 
{
	memset(&server_addr, 0, sizeof(server_addr));
	memset(&client_addr, 0, sizeof(client_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

Tcpip::~Tcpip()
{
	close(client_fd);
}

void Tcpip::send(string s) 
{
	write(client_fd, s.c_str(), s.size()+1);
}

string Tcpip::recv()
{
	int i = read(client_fd, buffer, 1024);
	buffer[i] = 0;
	return string(buffer);
}

Client::Client(string ip, int port) : Tcpip(port) 
{
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	if(-1 == connect(client_fd, (sockaddr*)&server_addr, sizeof(server_addr)))
		cout << "connect() error" << endl;
	else cout << " connecting"  <<endl;
}

Server::Server(int port, int queue) : Tcpip(port) 
{
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == -1)
		cout << "bind() error" << endl;
	else cout << "binding" << endl;
	if(listen(server_fd, queue) == -1) cout << "listen() error" << endl;
	else cout << "listening" << endl;
	int cl_size = sizeof(client_addr);
	if(client_fd = accept(server_fd, (sockaddr*)&client_addr, (socklen_t*)&cl_size) == -1)
		cout << "accept() error" << endl;
	else cout << "accepting" << endl;
}
