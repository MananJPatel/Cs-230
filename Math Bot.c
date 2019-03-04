#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  int cf, pt, x;
  struct sockaddr_in sv_addr;
  char *e, buffer1[256];

  pt = atoi(argv[2]);
  cf = socket(AF_INET,SOCK_STREAM,0);

  memset((char *) &sv_addr, 0, sizeof(sv_addr));
  sv_addr.sin_family = AF_INET;
  sv_addr.sin_port = htons(pt);
  sv_addr.sin_addr.s_addr = inet_addr(argv[3]);

  if(cf < 0){
    perror("error in socket while opening");
    exit(1);
  }
  if(connect(cf, (struct sockaddr*)&sv_addr, sizeof(struct sockaddr)) < 0){
    perror("error\n");
    exit(1);
  }
  memset(buffer1, 0, 256);
  strcpy(buffer1,"cs230 HELLO ");
  strcat(buffer1, argv[1]);
  strcat(buffer1,"\n");
  x=write(cf,buffer1,strlen(buffer1));

  if(x<0){
    perror("error in socket while writing");
    close(cf);
    exit(1);
  }

while(1){
    if(x<0){
      perror("error in socket while writing");
      close(cf);
      exit(1);
    }

    int ans, fn, sn, op = 3;
    char *i, flag;

    memset(buffer1,0,256);
    x=read(cf,buffer1,255);

    i = strtok(buffer1, " ");
    i=strtok(NULL, " ");
    
    if(strcmp(i,"STATUS")!=0){
      printf("cs230 %s BYE\n",i);
      close(cf);
      exit(0);
    }

    i=strtok(NULL, " ");

    fn=atoi(i);
    i=strtok(NULL, " ");

    if(strcmp(i,"/")==0){
       op=0;
    }
    if(strcmp(i,"*")==0){
       op=1;
    } 
    if(strcmp(i,"+")==0){
       op=2;
    }
    if(strcmp(i,"-")==0){
       op=3;
    }

    i=strtok(NULL, " ");
    sn=atoi(i);

    if(op==0){
       ans=fn/sn;
    }
    if(op==1){
       ans=fn*sn;
    }
    if(op==2){
       ans=fn+sn;
    }
    if(op==3){
       ans=fn-sn;
    }

    char a[256];
    sprintf(a, "%d\n", ans);
    memset(buffer1, 0, 256);
    strcpy(buffer1, "cs230 ");
    strcat(buffer1, a);
    x = write(cf, buffer1, strlen(buffer1));

    if(x<0){
      perror("no");
      close(cf);
      break;
    }
  }
  return 0;
}