#ifndef LAB15_H
#define LAB15_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

template <class T>
class MyStack  
{
private:
    //Create your queue field here    
    ds::da::Queue<T> myQ, myQu, tmp;
    int capacity, size;
    T *data; 
public:

    //Initialize your stack
    MyStack() : size(0){
        int capacity = 30;
    } 
    //adds element to the stack
    void Push(const T& value){
        size+=1;
        myQ.Enqueue(value);
        
        while(myQu.IsEmpty()!=true){
            myQ.Enqueue(myQu.Peek());
            myQu.Dequeue();
        }

        tmp = myQu;
        myQu = myQ;
        myQ = tmp;
    }
    //removes top element from the stack        
    void Pop(){
        if(myQu.IsEmpty()!=true){
            myQu.Dequeue();
            size-=1;
        }
        else {
            std::cout << "already empty" << std::endl;
        }
    }
    //retrieves but does not remove the top element of the stack 
    const T& Top() const{
        return myQu.Peek();
    }
    //states if the stack is empty
    bool IsEmpty() const{
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
};


template <class T>
class MyQueue  
{
private:
    //Create your stack field here 
   
public:
    //Initialize your queue
    MyQueue(
       
    );

    //adds element to the queue
    void Enqueue(const T& value);

    //removes front element from the queue        
    void Dequeue();

    //retrieves but does not remove the front element of the queue 
    const T& Peek() const;

    //states if the queue is empty
    bool IsEmpty() const;
};

#endif