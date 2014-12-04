/* 
 * File:   client.cpp
 * Author: cyberclub
 *
 * Created on November 26, 2014, 7:37 AM
 */

//#define LENGTH 150
//#include <cstdio>
//#include <sys/types.h>   // tipe data penting untuk sys/socket.h dan netinet/in.h
//#include <netinet/in.h>  // fungsi dan struct internet address
//#include <sys/socket.h>  // fungsi dan struct socket API
//#include <netdb.h>       // lookup domain/DNS hostname
//#include <unistd.h>
//#include <cstdlib>
//#include <errno.h>
//#include <cstring>
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <ctime>
//
//using namespace std;
//
//thread tread;
//mutex lock;
//int sock, port, len; 
//char s_buffer[150], c_buffer[150];
//struct sockaddr_in serv_addr;
//struct hostent *server;
//
//void readmessage(int sock)
//{
//    while(1)
//    {
//        read(sock,s_buffer,150);
//        printf("%s\n,buffer");
//    }
//}
//int main(int argc, char** argv){
//	// penggunaan: ./client <server ip>
//	if (argc != 2){
//		printf("Pemakaian: ./client <server ip>\n");
//                exit(1);
//	}
//	port = 9000;
//	// buka socket TCP (SOCK_STREAM) dengan alamat IPv4 dan protocol IP
//	if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
//		close(sock);
//		printf("Cannot open socket\n");
//		exit(1);
//	}
//	
//	// buat address server
//	server = gethostbyname(argv[1]);
//	if (server == NULL) {
//		fprintf(stderr,"Host not found\n");
//		exit(1);
//	}
//	
//	bzero((char *) &serv_addr, sizeof(serv_addr));
//	serv_addr.sin_family = AF_INET;
//	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
//	serv_addr.sin_port = htons(port);
//	
//	// connect ke server, jika error keluar
//	if (connect(sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) exit(1);
//	while(1){
//		bzero(c_buffer,150);
//		getline(cin,c_buffer);
//		
//		len = write(sock,c_buffer,150);
//		
//	}
//	
//	close(sock);
//	return 0;
//}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
	printf("Pemakaian: ./client <server ip>\n");
        exit(1);
    }
    Client C(argv[1]);
    C.threadinit();
}