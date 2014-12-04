/* 
 * File:   server.h
 * Author: kevhnmay94
 *
 * Created on November 28, 2014, 7:09 AM
 */

#ifndef SERVER_H
#define	SERVER_H
#include <map>
#include <mutex>
#include <thread>
#include <sys/types.h>   // tipe data penting untuk sys/socket.h dan netinet/in.h
#include <netinet/in.h>  // fungsi dan struct internet address
#include <sys/socket.h>  // fungsi dan struct socket API
#include <netdb.h>       // lookup domain/DNS hostname
#include <unistd.h>
#include <cstdlib>
#include <errno.h>
#include <cstring>
#include <iostream>
#include <ctime>
#include <vector>
#include "user.h"
#include "group.h"
#include "message.h"

using namespace std;

class Server
{
    private:
        mutex lock;
        int sock, client_sock;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	int port = 9000, n;
        //char s_buffer[150], c_buffer[150];
        map<int, char *> socketmap;
        map<char *,user> usermap;
        map<char *,group> groupmap;
        vector<thread> threadvector;
        int connected;
    public:
        Server();
        ~Server();
        // External
        void readmessage(int sockid);
        void writemessage(message m);
        void connect();
        // Internal
        void process(message m);
        void login();
        void logout();
        void signup();
        message tomessage();
        void writefile(int type);
        void readfile(int type);
};

#endif	/* SERVER_H */

