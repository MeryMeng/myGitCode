#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "CTO.h"
#include "SalesPerson.h"
#include "COO.h"
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

void init(void){
    if(access("id.txt",F_OK)==-1){
        FILE* fp = fopen("id.txt","w");//记录工号
        if(fp == NULL){
            perror("fopen"),exit(-1);
        }
        fprintf(fp,"%d",10001);
        fclose(fp);
    }
    if(access("count.txt",F_OK)==-1){
        FILE* fp = fopen("count.txt","w");//记录人数
        if(fp == NULL){
            perror("fopen"),exit(-1);
        }
        fprintf(fp,"%d",0);
        fclose(fp);
    }
    else{
        //加载员工人数
        Employee::getEmployeeCount();
    }
}

int main()
{
    init();
    Employee emp("张三",6600);
    emp.printInfo();
    emp.calSalary();
    cout << "===========================" << endl;

    Technician tech("张飞",8800,30);
    tech.printInfo();
    tech.calSalary();
    cout << "===========================" << endl;
    
    Manager manager("刘备",12000,5000);
    manager.printInfo();
    manager.calSalary();
    cout << "===========================" << endl;

    CTO cto("孔明",16000,30,5000);
    cto.printInfo();
    cto.calSalary();
    cout << "===========================" << endl;

    SalesPerson sale("周瑜",5000,0.05);
    sale.printInfo();
    sale.calSalary();
    cout << "===========================" << endl;

    COO coo("孙权",18000,0.05,5000);
    coo.printInfo();
    coo.calSalary();
    cout << "===========================" << endl;

    return 0;
}




