#include "SalesPerson.h"

SalesPerson::SalesPerson(const string& name,double salary,double percent)
	:Employee(name,salary),m_percent(percent){
        //保存员工绩效信息
        fprintf(file," %g",m_percent);    
}
void SalesPerson::printExtra(void){
 	cout << "职位：销售员" << endl; 
	cout << "提成比率:" << m_percent << endl;
}
double SalesPerson::calMerit(void){
        cout << "请输入销售额度:";
        double sales;
        cin >> sales;
        return sales*m_percent;
}
