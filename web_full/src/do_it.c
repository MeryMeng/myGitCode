#include <stdio.h>
#include "do_trans.h"
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
extern char *dir;

static void parse_get(request_t *rq){
    	char rpath[128];
	if(strchr(rq->path,'?')==NULL)
		rq->is_static=True;
	else{
		char path[128];
		rq->is_static=False;
		strcpy(path,rq->path);
		char *p=strtok(path,"?");
		strcpy(rq->path,p);
		p=strtok(NULL,"?");
		strcpy(rq->para,p);
	}
	//将请求路径转换为服务器的发布路径
    	bzero(rpath,128);
    	strcpy(rpath,dir);
        //队默认请求的处理
        if(strcmp(rq->path,"/")==0)
            strcpy(rq->path,"/index.html");

    	strcat(rpath,rq->path);
    	strcpy(rq->path,rpath);
	return;
}
static int get_len(const char *str){
	char *gp,*gq;
	char buf[512],rs[512];

	strcpy(buf,str);
	gp=strtok(buf,"\r");
	bzero(rs,512);
	strcpy(rs,gp);
	
	gq=strtok(rs," ");
	gq=strtok(NULL," ");
	
	return atoi(gq);
}
static void parse_post(const char *str,request_t *req){
	char request_body[1024];
        char *n;
        char name[32],value[128];
        char strings[256];
	char rs[128];
        char *p;
	int len;
	char rpath[128];

        strcpy(request_body,str);
        p=strtok(request_body,"\n");
        while((p=strtok(NULL,"\n"))!=NULL){
		
		if(strncmp(p,"Content-Length:",15)==0){
			printf("content-length:%s\n",p);
			bzero(strings,512);
			strcpy(strings,p);
		}
		bzero(rs,128);
		strcpy(rs,p);
        }
	len=get_len(strings);
	bzero(req->para,256);
	strncpy(req->para,rs,len);
    	bzero(rpath,128);
    	strcpy(rpath,dir);
    	strcat(rpath,req->path);
    	strcpy(req->path,rpath);
	return;
}

static void get_request(int fd,request_t *req){
    char buf[1024];
    char rpath[128];
    int r=read(fd,buf,1024);
#if 0
	write(1,buf,r);
	printf("\n");
#endif
    //获取首行
    sscanf(buf,"%s %s %s\r\n",\
            req->method,req->path,req->protocol);
    if(strcmp(req->method,"GET")==0)
	parse_get(req);
#if 1
    if(strcmp(req->method,"POST")==0){
	req->is_static=False;
	parse_post(buf,req);
    }
     printf("response_b get_request fd:%d\n",fd);
#endif

    return;
}

//获取文件的响应类型
static  char *get_ftype(const char *file){
    char *f_type;
    /*/home/tarena/web/html/a.html*/
    f_type=strrchr(file,'.');
    if(strcmp(f_type,".html")==0)return "text/html";
    if(strcmp(f_type,".jpg")==0)return "image/jpg";
    if(strcmp(f_type,".png")==0)return "image/png";
    return "text/html";

}
//完善响应信息
static void do_request(response_t *rs){
	printf("do request path:%s\n",rs->rq->path);
	if(rs->rq->is_static==True){
    		rs->code=access(rs->rq->path,R_OK)? 404:200;
	}else{
		rs->code=access(rs->rq->path,X_OK)? 404:200;
	}

    	if(rs->code==404){
		bzero(rs->rq->path,128);
		strcpy(rs->rq->path,dir);
		strcat(rs->rq->path,"/error.html");
    	}

    	rs->f_type=get_ftype(rs->rq->path);

    return;
}
static void response_b_s(int fd,response_t *rs){
	
    	char f_line[128],content[128];
	char command[256];
    	bzero(f_line,128),bzero(content,128);
    	sprintf(f_line,"%s %d\r\n",rs->rq->protocol,rs->code);
    	sprintf(content,"Content-Type:%s\r\n\r\n",rs->f_type);
    	write(fd,f_line,strlen(f_line));
    	write(fd,content,strlen(content));
    	dup2(fd,1);//将标准输出重定向到浏览器
	//dynamic not end
    	execlp("cat","cat",rs->rq->path,NULL);
	return;
}
static void response_b(int fd,response_t *rs){
    	char f_line[128];
	if(rs->code==404){
		response_b_s(fd,rs);
		return;
	}
	if(rs->rq->is_static==True){
    		response_b_s(fd,rs);
		return;
	}else{
    		bzero(f_line,128);
    		sprintf(f_line,"%s %d\r\n",rs->rq->protocol,rs->code);
    		write(fd,f_line,strlen(f_line));
		dup2(fd,1);
		setenv("QUERY_STRING",rs->rq->para,1);
		execl(rs->rq->path,"path",NULL);
	}
    	return;
}

//对客户端的请求数据进行处理
void do_trans(int fd){
    request_t req;
    response_t  res;
    int sfd=fd;
    printf("response_b fd:%d\n",fd);
    //获取客户的请求，解析请求首行，获取请求信息
    get_request(fd,&req);
    res.rq=&req;
    //根据请求信息，处理用户的请求，形成响应信息
    do_request(&res);
    
    //使用响应信息，响应客户端
    response_b(sfd,&res);
    return;
}
