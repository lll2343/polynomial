#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>
#include "NoMen.h"
#include "OutOfBounds.h"

template<typename T>
class myList{
public:
    //构造函数，生成一个空的头结点
    myList() { head = new Node<T>; count = 0; }
    myList(myList<T>const& another); 
    myList<T>& operator=(myList<T>const&copy);
    ~myList();
    bool isEmpty() const { return head->next==nullptr; }
    myList<T>& clear();
    myList<T>& pushBack(const T data);
    myList<T>& popBack(T &data);
    myList<T>& pushFrout(const T data);
    myList<T>& popFrout(T &data);
    myList<T>& Insert(const int i,const T& data);
    myList<T>& Delete(const int i,T &data);//按照下标删除，并将该下标处的内容保存到data中
    myList<T>& Delete(const T &data);//按照内容删除
    myList<T>& SetElem(const int i,const T& data);
    void showList();
    int Size() const { return count; }
    bool find(const int i,T& data) const;
private:
    Node<T> *head;
    int count;
};

template<typename T>
myList<T>::myList(myList<T>const& another){
    head = new Node<T>;
    count = 0;
    int count_i = 0;
    T temp;
    while(count_i < another.count){
        bool flag = another.find(count_i++,temp);
        this->pushBack(temp);
    }
}

template<typename T>
myList<T>& myList<T>::clear(){
    if(!isEmpty()){
        Node<T> *temp=head->next;
        Node<T> *p = temp;
        while(temp->next != nullptr){
            temp=temp->next;
            delete p;
            p = temp;
        }
        delete p;
        count = 0;
        head->next = nullptr;
    }
    return *this;
}

template<typename T>
myList<T>& myList<T>::operator=(myList<T>const& copy){
    this->clear();
    int count_i = 0;
    T temp;
    while(count_i < copy.count){
        copy.find(count_i++,temp);
        pushBack(temp);
    }
    return *this;
}

template<typename T>
myList<T>::~myList(){
    Node<T> *p = head;
    while(p != nullptr){
        head = head -> next;
        delete p;
        p = head;
    }
    delete p;
}

template<typename T>
myList<T>& myList<T>::pushBack(const T data){
    Node<T> *p = head;
    while(p->next!=nullptr)
        p=p->next;
    Node<T> *q = new Node<T>;
    q->data = data;
    p->next = q;
    count++;
    return *this;
}

template<typename T>
myList<T>& myList<T>::popBack(T &data){
    if(head->next == nullptr)
        throw NoMen();

    Node<T> *p = head;
    int i = 0;
    while(i++ < count-1)
        p = p->next;
    data = p->next->data;//保存data值
    delete p->next;
    p->next = nullptr;
    count--;
    return *this;
}

template<typename T>
myList<T>& myList<T>::pushFrout(const T data){
    Node<T> *temp = new Node<T>;
    temp->data = data;
    Node<T>* p = head->next;
    head->next = temp;
    temp->next = p;
    count++;
    return *this;
}

template<typename T>
myList<T>& myList<T>::popFrout(T &data){
    if(head->next == nullptr)
        throw NoMen();

    Node<T> *p = head->next;
    data = p->data;
    head->next = p->next;
    delete p;
    count--;
    return *this; 
}

template<typename T>
void myList<T>::showList(){
    Node<T> *p = head->next;
    int i = 0;
    while(p != nullptr){
        std::cout<<p->data<<"\t";
        p = p->next;
    }
    std::cout<<"\n";
}

template<typename T>
myList<T>& myList<T>::Insert(const int i,const T& data){
    if(i<0 || i > count)
        throw OutOfBounds();
    
    Node<T> *p = head;
    int count_i = 0;
    while(count_i++ < i)
        p = p->next;
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    count++;

    return *this;
}

template<typename T>
myList<T>& myList<T>::Delete(const int i,T &data){
    if(i<0 || i > count)
        throw OutOfBounds();

    int count_i = 0;
    Node<T> *p = head;
    while(count_i++ < i)
        p = p->next;
    Node<T>* temp = p->next;
    data = temp->data;
    p->next = temp->next;
    delete temp;
    count--;

    return *this;
}

template<typename T>
myList<T>& myList<T>::Delete(const T& data){
    //按照内容查找，删除链表中所有值为data的节点
    Node<T>* p =  head;
    Node<T>* q = p->next;
    int num = count;
    for(int count_i = 0;count_i < num && q->next != nullptr;count_i++){
        if(q->data  == data){
            p->next = q->next;
            delete q;
            count--;
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
    }

    return *this;
}

template<typename T>
bool myList<T>::find(const int i,T &data) const {
    if(i<0 || i >= count)
        return false;

    Node<T> *p = head->next;
    int count_i = 0;
    while(count_i++ < i)
        p = p->next;
    data = p->data;
    return true;
}

template<typename T>
myList<T>& myList<T>::SetElem(const int i,const T& data){
    if(i<0 || i > count)
        throw OutOfBounds();

    if(!this->isEmpty()){
        Node<T> *p = head->next;
        int count_i=0;
        while(count_i++ < i )
            p = p->next;
        p->data = data;
    }
    return *this;
}

#endif //LIST_H