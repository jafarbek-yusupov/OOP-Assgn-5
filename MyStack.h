#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <stdexcept>

template <typename T>
class MyStack{
private:
    class MyListNode{ public: T value; MyListNode* next; MyListNode(T value) : value(value), next(nullptr) {}};
    MyListNode* head;

public:
    MyStack() : head(nullptr) {}
    ~MyStack(){ while(!empty()){ pop();}}
    bool empty() const{ return head == nullptr;}
    T top() const{ if(empty()){ throw std::logic_error("Stack is empty\n");} return head->value;}
    
    void pop(){
        if(empty()){ throw std::logic_error("Stack is empty\n");}
        MyListNode* temp = head; head = head->next; delete temp;
    }
    
    void push(T vv){ MyListNode* nn = new MyListNode(vv); nn->next = head; head = nn;}
};

#endif
