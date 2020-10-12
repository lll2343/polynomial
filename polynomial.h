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
private:
    myList<polyItem>  polyList;  //多项式组成的线性表
};

#endif //POLYNOMIAL_H