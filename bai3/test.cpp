#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
void clean_stdin(void){
    int c;
    do{
        c = getchar();
    }while (c!='\n' && c!=EOF);
}
int main(){
    // char name[100];
    // char MSSV[100];
    // char msg[256];
    // while (1){
    // strcpy(msg,"");
    // printf("Enter name: ");
    // fgets(name,sizeof(name),stdin);
    // name[strcspn(name,"\n")] = '\0';
    // strcat(msg,name);
    // strcat(msg," ");
    // printf("Enter MSSV: ");
    // fgets(MSSV,sizeof(MSSV),stdin);
    // name[strcspn(MSSV,"\n")] = '\0';
    // strcat(msg,MSSV);
    // printf("MSSV: ");
    // fputs(MSSV,stdout);
    // printf("name: ");
    // fputs(,stdout);
    // fputs(msg,stdout);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char res[256];
    snprintf(res,sizeof(res),"now: %d-%d-%d %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    //printf("now: %d-%d-%d %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    printf("res: %s",res);
    return 0;
}