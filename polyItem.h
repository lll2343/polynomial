#ifndef POLYITEM_H
#define POLYITEM_H

class polyItem
{
public:
    double coef; //系数
    int expn; //指数;

    //构造函数
    polyItem() : expn(-1) {} //构造指数域为-1的结点
    polyItem(double cf,int en);
    polyItem(polyItem& copy);
};

polyItem::polyItem(double cf,int en){
    this->coef =cf;
    this->expn = en;
}

polyItem::polyItem(polyItem& copy){
    this->coef = copy.coef;
    this->expn = copy.expn;
}

#endif //POLYITEM_H