#include "polyItem.h"
#include "List.h"
#include "polynomial.h"
using namespace std;

int main(){
    myList<int> l1;
    for(int i=0;i<4;i++)
        l1.pushBack(i);

    myList<int> l2=l1;
    l2.showList();    
    int a;
    l1.find(1,a);
    cout<<a<<endl;

    return 0;;
}