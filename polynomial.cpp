#include "polynomial.h"

polynomial& polynomial::operator=(const polynomial& copy)
{
    this->polyList = copy.polyList;
}

polynomial& polynomial::operator=(const myList<polyItem>& copyLinkList)
{
    this->polyList = copyLinkList;
}

polynomial polynomial::operator+(const polynomial& p) const
{
    myList<polyItem> la = this->polyList;

}