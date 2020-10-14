#ifndef POLYITEM_H
#define POLYITEM_H

#include <iostream>
using namespace std;

class polyItem
{
public:
    double coef; //系数
    int expn; //指数;

    //构造函数
    polyItem() : expn(-1) {} //构造指数域为-1的结点
    polyItem(double cf,int en);
    polyItem(polyItem& copy);
    polyItem& operator=(const polyItem& copy);

    friend ostream& operator<<(ostream& out,const polyItem& p);
};

polyItem::polyItem(double cf,int en){
    this->coef =cf;
    this->expn = en;
}

polyItem::polyItem(polyItem& copy){
    this->coef = copy.coef;
    this->expn = copy.expn;
}

ostream& operator<<(ostream& out,const polyItem& p){
    out<<p.coef<<"*X^"<<p.expn;
    return out;
}

polyItem& polyItem::operator=(const polyItem& copy){
    this->coef = copy.coef;
    this->expn = copy.expn;
}

#endif //POLYITEM_H