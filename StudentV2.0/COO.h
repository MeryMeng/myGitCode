#ifndef __COO_H_
#define __COO_H_

#include "SalesPerson.h"
#include "Manager.h"

class COO:public SalesPerson,public Manager{
public:
    COO(const string& name,double salary,
        double percent,double bonus);
protected:
    void printExtra(void)const;
    double calMerit(void);
};

#endif//__COO_H_
