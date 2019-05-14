#include <stdio.h>
#include "config.h"
//extern int errno;
int log_fd=-1;
//get config and set environ
int get_conf(const char *file){
	FILE *fp;
	char buf[256];
	char name[128],value[128];
	fp=fopen(file,"r");
	if(fp==NULL){
		perror("fopen config");
		return -1;
	}
	while(fscanf(fp,"%s\n",buf)!=EOF){
		if(buf[0]=='#')continue;
		sscanf(buf,"%[^=]=%s",name,value);
		setenv(name,value,1);
	}
	fclose(fp);
	return 0;
}
//error log
int init_logfile(const char *filename){
	log_fd=open(filename,O_WRONLY|O_CREAT|O_APPEND,0664);
	if(log_fd==-1){
		perror("log_fd open");
		return -1;
	}
	return log_fd;
}

void sys_err(const char *str){
	char msg[256];
	
	sprintf(msg,"file:%s\tline:%d\nreason:%s\n",
		__FILE__,__LINE__,strerror(errno));
	write(log_fd,msg,strlen(msg));
	return;
}


