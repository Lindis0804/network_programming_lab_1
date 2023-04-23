#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[]){
    char * ipAddr = new char[20];
    strcpy(ipAddr,argv[1]);
    int port;
    sscanf(argv[2],"%d",&port);
    //initialize socket
    int client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (client == -1){
        printf("socket() failed.");
        return 1;
    }
    //khai báo cấu trúc địa chỉ client
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipAddr);
    addr.sin_port = htons(port);
    //kết nối đến server
    int ret = connect(client,(struct sockaddr *)&addr,sizeof(addr));
    if (ret == -1){
        perror("connect() failed.");
        return 1;
    }
    char buf[256];
    //nhận dữ liệu từ server
    ret = recv(client,buf,sizeof(buf),0);
    if(ret <=0){
        printf("Connection closed\n");
        return 1;
    }
    if (ret < sizeof(buf)){
        buf[ret] = 0;
    }
    printf("%d bytes received: %s\n",ret,buf);
    
    char * MSSV = new char[8];
    char *name = new char[100];
    char *dateOfBirth = new char[100];
    float GPA;
    char * strGPA = new char[5];
    char * msg = new char[256];
    char sep[5] = "//" ;
    //gửi dữ liệu đến server
    while (1){
        strcpy(msg,"");
        printf("Enter MSSV: ");
        fflush(stdin);
        fgets(MSSV,sizeof(MSSV),stdin);
        MSSV[strcspn(MSSV,"\n")]='\0';
        printf("Enter name: ");
        fflush(stdin);
        fgets(name,sizeof(name),stdin);
        name[strcspn(name,"\n")]='\0';
        printf("Enter dateOfBirth: ");
        fflush(stdin);
        fgets(dateOfBirth,sizeof(dateOfBirth),stdin);
        dateOfBirth[strcspn(dateOfBirth,"\n")]='\0';
        printf("Enter GPA: ");
        cin>>GPA;
        sprintf(strGPA,"%f",GPA);
        strcat(msg,MSSV);
        strcat(msg,sep);
        strcat(msg,name);
        strcat(msg,sep);
        strcat(msg,dateOfBirth);
        strcat(msg,sep);
        strcat(msg,strGPA);
        strcat(msg,sep);
        printf("msg: %s",msg);
        send(client,msg,strlen(msg),0);
    }
    close(client);
    delete[] ipAddr;
    return 0;

}