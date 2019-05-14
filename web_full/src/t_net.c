#include <stdio.h>
#include "t_net.h"
#include "config.h"

int socket_b(int port){
    //struct sockaddr serv;//通用地址类型
    SA4 serv;//ipv4地址家族
    //创建通讯端点,返回新建通讯端点的文件描述符
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd==-1){
        sys_err("socket");
        return -1;
    }
    int opt=1;
    setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    //需要初始化serv的各个成员变量
    serv.sin_family=AF_INET;
    serv.sin_port=htons(port);
    //INADDR_ANY 代表本机所有的ip地址  宏
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    //将sfd和本地的ip地址和端口绑定
    int b=bind(sfd,(SA *)&serv,sizeof(serv));
    if(b==-1){
        sys_err("bind");
        return -1;
    }
    return sfd;//绑定了地址空间的sfd
}
