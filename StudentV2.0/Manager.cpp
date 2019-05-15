#include "Manager.h"

Manager::Manager(const string& name,double salary,double bonus)
    :Employee(name,salary),m_bonus(bonus){
    //保存经理的绩效奖金
    fprintf(file," %g",m_bonus);    
}
void Manager::printExtra(void)const{
    cout << "职位:经理" << endl;
    cout << "绩效奖金:" << m_bonus << endl;
}
double Manager::calMerit(void){
    cout << "请输入绩效因数:";
    double factor;
    cin >> factor;
    return m_bonus * factor;
}


