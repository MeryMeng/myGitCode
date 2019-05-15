#include "COO.h"

COO::COO(const string& name,double salary,double percent,double bonus):
    SalesPerson(name,salary,percent),Manager(name,salary,bonus),Employee(name,salary){}

void COO::printExtra(void)const{
    cout << "职位:销售主管" << endl;
    cout << "提成比率:" << m_percent << endl;
    cout << "绩效奖金:" << m_bonus << endl;
}
double COO::calMerit(void){
     //销售员+经理/2
    return (SalesPerson::calMerit() + Manager::calMerit())/2;
}
