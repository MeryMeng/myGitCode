#ifndef DO_TRANS_H_
#define DO_TRANS_H_
/*文件的包含*/
#include <unistd.h>
#include <ctype.h>
typedef enum{False,True}bool_t;
/*类型的定义*/
typedef struct{
    char method[16];///////////////////////////////////***********
    char path[128];
    char protocol[16];
    bool_t is_static;
    char para[128];////////*****************//////******************
}request_t;//保存请求信息的结构体

typedef struct{
    request_t *rq;
    int code;
    char *f_type;
}response_t;//响应信息头

//对客户端的请求数据进行处理
void do_trans(int fd);
#endif

