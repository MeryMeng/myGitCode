#ifndef __SALESPERSON_H
#define __SALESPERSON_H

#include "Employee.h"

class SalesPerson:virtual public Employee{
public:
    SalesPerson(const string& name,double salary,double percent);
protected:
    void printExtra(void);
    double calMerit(void);
    double m_percent;//百分比
};

#endif//__SALESPERSON_H
