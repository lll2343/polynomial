#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "polyItem.h" 
#include "List.h"

class polynomial{
public:
    polynomial() {};//无参构造函数
    ~polynomial() {};
    int Length() const;
    bool isZreo() const;
    void SetZero();
    void display();
    void InsItem(const polyItem& item);
    polynomial operator+(const polynomial &p) const;
    polynomial operator-(const polynomial &p) const;
    polynomial operator*(const polynomial &p) const;
    polynomial(const polynomial& copy);
    polynomial(const myList<polyItem>& copyLinkList);
    //由多项式组成的线性表构造多项式
    polynomial& operator=(const polynomial& copy);
    polynomial& operator=(const myList<polyItem>& copyLinkList);
    void showpolynomial();
private:
    myList<polyItem>  polyList;  //多项式组成的线性表
};

#endif //POLYNOMIAL_H

// # include "polynomial.h"

polynomial& polynomial::operator=(const polynomial& copy)
{
    this->polyList = copy.polyList;
}

polynomial& polynomial::operator=(const myList<polyItem>& copyLinkList)
{
    this->polyList = copyLinkList;
}

polynomial::polynomial(const polynomial& copy)
{
    this->polyList = copy.polyList;
}

polynomial::polynomial(const myList<polyItem>& copyLinkList)
{
    this->polyList = copyLinkList;
}

polynomial polynomial::operator+(const polynomial& p) const
{
    myList<polyItem> la = this->polyList;
    myList<polyItem> lb = p.polyList;
    myList<polyItem> lc;
    //链表下标从零开始
    int aPos=0,bPos=0;
    polyItem aItem,bItem;

    bool aFlag = la.find(aPos,aItem);
    bool bFlag = lb.find(bPos,bItem);
    //取出la.lb的第0项
    while (aFlag && bFlag)
    {
        /* code */
        if(aItem.expn < bItem.expn){
            lc.pushBack(aItem);
            aFlag = la.find(++aPos,aItem);
        }
        else if(aItem.expn > bItem.expn){
            lc.pushBack(bItem);
            bFlag = lb.find(++bPos,bItem);
        }
        else{
            polyItem sumItem(aItem.coef+bItem.coef,aItem.expn);
                if(sumItem.coef != 0)
                    lc.pushBack(sumItem);
                aFlag = la.find(++aPos,aItem);
                bFlag = lb.find(++bPos,bItem);
        }
    }

    //将剩余的追加到lc的后面
    while(aFlag){
        lc.pushBack(aItem);
        aFlag = la.find(++aPos,aItem);
    }
    
    while(bFlag){
        lc.pushBack(bItem);
        bFlag = lb.find(++bPos,bItem);
    }

    polynomial fs;
    fs = lc;

    return fs;
}

polynomial polynomial::operator-(const polynomial& p) const{
    //对于减法，可以P(x)-Q(x) = P(x) + (-Q(X))
    myList<polyItem> la = this->polyList;
    myList<polyItem> lb = p.polyList;
    //链表下标从零开始
    int bPos = 0;
    polyItem bItem;
    bool bFlag;
    bFlag = lb.find(bPos,bItem);
    while(bFlag){
        bItem.coef = - bItem.coef;
        lb.SetElem(bPos,bItem);
        bFlag = lb.find(++bPos,bItem);
    }

    polynomial fa(la),fb(lb),fc = fa + fb;

    return fc;
}

polynomial polynomial::operator*(const polynomial& p) const{
    myList<polyItem> la = this->polyList;
    myList<polyItem> lb = p.polyList;
    myList<polyItem> lc;
    polynomial fMultiply;
    int aPos = 0,bPos;
    polyItem aItem,bItem,cItem;
    bool aFlag,bFlag;
    aFlag = la.find(aPos,aItem);
    while(aFlag){
        bPos = 0;
        bFlag = lb.find(bPos,bItem);
        while(bFlag){
            cItem.coef = aItem.coef * bItem.coef; //系数相乘
            cItem.expn = aItem.expn + bItem.expn; //指数相加
            lc.clear();
            lc.pushBack(cItem);
            polynomial fc(lc);
            fMultiply = fMultiply + fc;
            //取出lb 的下一项
            bFlag = lb.find(++bPos,bItem);
        }
        aFlag = la.find(++aPos,aItem);
    }
    return fMultiply;
}

void polynomial::showpolynomial(){
    this->polyList.showList();
}