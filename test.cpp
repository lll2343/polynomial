#include "polyItem.h"
#include "List.h"
#include "polynomial.h"
using namespace std;

int main(){
    polyItem a1(1,2);
    polyItem a2(2,3);

    myList<polyItem> m1;
    m1.pushBack(a1);
    m1.pushBack(a2);
    
    polynomial p1(m1);
    polynomial p2 = p1;
    p2=p1+p1;
    p2.showpolynomial();

    return 0;
}