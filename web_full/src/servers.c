#include <stdio.h>
#include "t_net.h"
#include "config.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "do_trans.h"
#include <signal.h>
void handle(int n){
    wait(NULL);
}
char *dir;
int main(void){
    //struct sockaddr serv;//通用地址类型
    SA4 clie;//ipv4地址家族
    socklen_t cli_len;
    int cfd;
    char IP[128];
    char web_dir[128];
    int port=7070;
    log_fd=init_logfile("error.log");
    if(log_fd==-1)return -1;

    int ret=get_conf("web.conf");
    if(ret==-1){
	printf("get config error\n");
	return -1;
    }
    dir=getenv("web_dir");
    char *pt=getenv("web_port");
    if(pt!=NULL)
         port=atoi(pt);
    if(dir==NULL)return -1;
    signal(SIGCHLD,handle);	
    int sfd=socket_b(port);
    if(sfd==-1) return -1;
    //设置sfd为被动连接
    listen(sfd,5);
    while(1){//死 loop
        cli_len=sizeof(clie);
        //从未决连接队列中取第一个连接请求，并处理这个连接请求，返回连接描述符，不支持来电显示
        cfd=accept(sfd,(SA *)&clie,&cli_len);
        if(cfd==-1){
            sys_err("accept");
            return -1;
        }
        //增加来电显示binary to  text
        printf("new link.......%s\n",inet_ntop(AF_INET,&clie.sin_addr,IP,128));
        //创建子进程
        pid_t pid=fork();
        if(pid==-1){
            sys_err("fork");
            return -1;
        }
        if(pid==0){//子进程的任务
            close(sfd);
            //到这里的时候，三次握手已经成功了
            //对客户端的请求数据进行处理
            do_trans(cfd);//只是在这里改动代码即可。
            //关闭本次连接
            close(cfd);
            exit(0);
            
        }else//父进程的任务
            close(cfd);
    }
    return 0;
}
