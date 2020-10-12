#include "polyItem.h"
#include "List.h"
using namespace std;

int main(){
    myList<int> la;
    for(int i=0;i<4;i++)
        la.pushBack(i);
    
    cout<<"la.find(1) "<<la.find(1)<<endl;

    return 0;;
}