/* 
 * File:   server.cpp
 * Author: cyberclub
 *
 * Created on November 26, 2014, 7:34 AM
 */

#define LENGTH 150
#include <cstdio>
#include <sys/types.h>   // tipe data penting untuk sys/socket.h dan netinet/in.h
#include <netinet/in.h>  // fungsi dan struct internet address
#include <sys/socket.h>  // fungsi dan struct socket API
#include <netdb.h>       // lookup domain/DNS hostname
#include <unistd.h>
#include <cstdlib>
#include <errno.h>
#include <cstring>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;

//mutex lock;
//
//char * process(char * input)
//{
//    
//}
//
//void run(int c)
//{
//    int len;
//    char c_buffer[LENGTH];
//    char s_buffer[LENGTH];
//    while(1)
//    {
//
//            // kosongkan buffer
//            bzero(c_buffer, 150);
//
//            // baca dari klien
//            len = read(c, c_buffer, 150);
//
//            if (len >= 0){ // jika pembacaan berhasil
//                    printf("Recv: %s\n",c_buffer);
//                    lock.lock();
//                    write(c,process(c_buffer),150);
//                    lock.unlock();
//            }
//    }
//    // tutup koneksi klien
//    close(c);
//}
//
//int main()
//{
//	int sock, client_sock;
//	socklen_t clilen;
//	struct sockaddr_in serv_addr, cli_addr;
//	int port = 9000, n;
//	
//	// buka socket TCP (SOCK_STREAM) dengan alamat IPv4 dan protocol IP
//	if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
//		close(sock);
//		printf("Cannot open socket\n");
//		exit(1);
//	}
//	
//	// ganti opsi socket agar dapat di-reuse addressnya
//	int yes = 1;
//	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
//		perror("Cannot set option\n");
//		exit(1);
//	}
//	
//	// buat address untuk server
//	bzero((char *) &serv_addr, sizeof(serv_addr));
//	serv_addr.sin_family = AF_INET;
//	serv_addr.sin_addr.s_addr = INADDR_ANY; // semua address pada network interface
//	serv_addr.sin_port = htons(9000); // port 9000
//	
//	// bind server ke address
//	if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
//		close(sock);
//		printf("Cannot bind socket\n");
//		exit(1);
//	}
//	
//	listen(sock,5); // listen ke maksimal 5 koneksi klien
//	
//	while(1){
//		// terima koneksi dari klien
//		clilen = sizeof(cli_addr);
//		client_sock = accept(sock, (struct sockaddr *) &cli_addr, &clilen);
//		new std::thread(run,client_sock);
//	}
//	close(sock);
//	return 0;
////}


