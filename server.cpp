#include "server.h"

Server::Server()
{
    // buka socket TCP (SOCK_STREAM) dengan alamat IPv4 dan protocol IP
	if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
		close(sock);
		printf("Cannot open socket\n");
		exit(1);
	}
	
	// ganti opsi socket agar dapat di-reuse addressnya
	int yes = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
		perror("Cannot set option\n");
		exit(1);
	}
	
	// buat address untuk server
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; // semua address pada network interface
	serv_addr.sin_port = htons(9000); // port 9000
	
	// bind server ke address
	if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		close(sock);
		printf("Cannot bind socket\n");
		exit(1);
	}
	listen(sock,10); // listen ke maksimal 5 koneksi klien
	
}

Server::~Server()
{
    close(sock);
}

void Server::readmessage(int sockid)
{
    int len;
    message fromclient;
    while(connected)
    {
        len = read(sockid,fromclient,sizeof(message));
        if(len >= 0)
        {
            writemessage(fromclient);
        }
        else
        {
            connected = false;
        }
    }
    close(sockid);
    
}

void Server::writemessage(message m)
{
    
}

void Server::connect()
{
    while(1)
    {
        // terima koneksi dari klien
        clilen = sizeof(cli_addr);
        client_sock = accept(sock, (struct sockaddr *) &cli_addr, &clilen);
        threadvector.push_back(thread(readmessage,client_sock));
    }
}

void Server::login()
{
    
}

void Server::logout()
{
    
}

void Server::signup()
{
    
}

void Server::writefile(int type)
{
    
}

void Server::readfile(int type)
{
    
}

