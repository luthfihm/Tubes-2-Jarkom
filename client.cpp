#include "client.h"

Client::Client(char* servername)
{
    port = 9000;
	// buka socket TCP (SOCK_STREAM) dengan alamat IPv4 dan protocol IP
	if((this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
		printf("Tidak dapat membuka socket\n");
		exit(1);
	}
	
	// buat address server
	server = gethostbyname(servername);
	if (server == NULL) {
		fprintf(stderr,"Host tidak ditemukan\n");
		exit(1);
	}
	
	bzero((char *) &(this->serv_addr), sizeof(this->serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&(this->serv_addr).sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(this->port);
	
	// connect ke server, jika error keluar
	if (connect(this->sock,(struct sockaddr *) &(this->serv_addr),sizeof(this->serv_addr)) < 0) exit(1);
        else this->connected=true;
}

Client::~Client()
{
    close(sock);
    printf("Goodbye.\n");
}

void Client::readmessage()
{
    int len;
    message fromserver;
    while(this->connected)
    {
        len = read(sock,fromserver,sizeof(message));
        if(len >= 0)
        {
            process(&fromserver);
        }
        else
        {
            this->connected = false;
        }
    }
    close(this->sock);
    
}

void Client::writemessage()
{
    char buffer[150];
    while(this->connected)
    {
        buffer = fgets(buffer,150,stdin);
        message toserver = tomessage(buffer);
        if(writecond1(&toserver))
        {
            loginorsignup(&toserver);
        }
        else if((toserver.type==1 || toserver.type==10) && strlen(this->username)!=0)
        {
            printf("You are already logged in. \n");
        }
        else if((!toserver.type==1 && !toserver.type==10) && strlen(this->username)==0)
        {
            printf("You are not logged in.\n");
        }
        if(writecond1(&toserver) || writecond2(&toserver))
        {
            int len = write(this->sock,toserver,sizeof(message));
            if(len < 0)
            {
                printf("Cannot send message to server\n");
            }
        }
        
    }
}

message Client::tomessage(char * b)
{
    message ret;
    strcpy(ret.s_user,this->username);
    char * c;
    strcpy(b,c);
    char * command = strtok(c, " ");
    if(strcmp(command,"login")==0)
    {
        ret.type = 1;
    }
    else if(strcmp(command,"message")==0)
    {
        command = strtok(NULL, " ");
        if(strcmp(command,"user")==0)
        {
            ret.type = 2;
        }
        else if(strcmp(command,"group")==0)
        {
            ret.type = 3;
        }
        command = strtok(NULL, " ");
        strcpy(ret.d_user,command);
        command = strtok(NULL, "\0");
        strcpy(ret.content,command);
        
    }
    else if (strcmp(command,"create")==0)
    {
        ret.type = 4;
        command = strtok(NULL, " ");
        strcpy(ret.d_user,command);
    }
    else if(strcmp(command,"join")==0)
    {
        ret.type = 5;
        command = strtok(NULL, " ");
        strcpy(ret.d_user,command);
    }
    else if(strcmp(command,"leave")==0)
    {
        ret.type = 6;
        command = strtok(NULL, " ");
        strcpy(ret.d_user,command);
    }
    else if(strcmp(command,"show")==0)
    {
        command = strtok(NULL, " ");
        if(strcmp(command,"user")==0)
        {
            ret.type = 7;
        }
        else if(strcmp(command,"group")==0)
        {
            ret.type = 8;
        }
        command = strtok(NULL, " ");
        strcpy(ret.d_user,command);
    }
    else if(strcmp(command,"logout")==0)
    {
        ret.type = 9;
    }
    else if(strcmp(command,"signup")==0)
    {
        ret.type = 10;
    }
    else
    {
        ret.type = 0;
    }
    return ret;   
    
}

void Client::loginorsignup(message * m)
{
    char username[20];
    char password[20];
    printf("Username: ");
    username = fgets(username,20,stdin);
    strcpy(m->s_user,username);
    printf("Password: ");
    password = fgets(password,20,stdin);
    strcpy(m->content,password);
}

void Client::logout()
{
    connected = false;
}

void Client::writefile(int type)
{
    
}

void Client::readfile(int type)
{
    
}

void Client::threadinit()
{
    thread readthread(readmessage), writethread(writemessage);
    readthread.join();
    writethread.join();
}

bool Client::writecond1(message * toserver) {
    return (toserver->type==1 || toserver->type==10) && strlen(this->username==0);
    
}

bool Client::writecond2(message * toserver) {
    return (!toserver->type==1 && !toserver->type==10) && strlen(this->username!=0);
    
}

void process(message * m)
{
    
}