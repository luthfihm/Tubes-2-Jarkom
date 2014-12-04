/* 
 * File:   client.h
 * Author: kevhnmay94
 *
 * Created on November 28, 2014, 7:09 AM
 */

#ifndef CLIENT_H
#define	CLIENT_H

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
#include "message.h"
using namespace std;

class Client
{
    private:
        mutex lock;
        int sock, port; 
        struct sockaddr_in serv_addr;
        struct hostent *server;
        char username[20];
        bool connected;
    public:
        Client(char* servername);
        ~Client();
        // External
        void readmessage();
        void writemessage();
        // Internal
        message tomessage();
        void process(message * m);
        void writefile(int type);
        void readfile(int type);
        void loginorsignup(message * m);
        void logout();
        void threadinit();
        bool writecond1(message * toserver);
        bool writecond2(message * toserver);
        
};


#endif	/* CLIENT_H */

