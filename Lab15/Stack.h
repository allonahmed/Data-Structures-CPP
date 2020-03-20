#ifndef STACK_H
#define STACK_H

/******************************************************
 * Data Structure: Stack
 * Description: It is a collection of objects that 
 * allows access to only one item at a time. It 
 * dispenses objects in the order last in first out.
 ******************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

/******************************************************
 * The implementation of a data structure is not 
 * unique, it can be implemented in numerous ways. The 
 * important thing is that the data structure performs
 * as expected and efficiently.
 ******************************************************/
namespace ds 
{
    template <class T>
    class StackInterface 
    {
    public:
        virtual void Push(const T&) = 0;
        virtual void Pop() = 0;
        virtual const T& Top() const = 0;
        virtual bool IsEmpty() const = 0;
    };

    namespace da
    {
        template <class T>
        class Stack : public StackInterface<T> 
        {
        private:
            T* data;
            int capacity;
            int top;

            void Resize(int ncp)
            {
                if(ncp <= 0)
                {
                    ncp = capacity * 2;
                }

                int tcp = (capacity < ncp)?(capacity):(ncp);

                T* tmp = new T[tcp];

                for(int i = 0;i < tcp;i += 1)
                {
                    tmp[i] = data[i];
                }

                capacity = ncp;
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < tcp;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }

        public:
            Stack() : Stack(30) {}

            Stack(int capacity) : capacity(capacity), top(0)
            {
                if(this->capacity <= 0)
                {
                    this->capacity = 30;
                }

                data = new T[this->capacity];
            }

            Stack(const Stack<T>& obj)
            {
                top = obj.top;
                capacity = obj.capacity;
                data = new T[capacity];

                for(int i = 0;i < top;i += 1)
                {
                    data[i] = obj.data[i];
                }
            }

            Stack<T>& operator=(const Stack<T>& rhs)
            {
                if(this != &rhs)
                {
                    top = rhs.top;
                    capacity = rhs.capacity;
                    delete[] data;
                    data = new T[capacity];

                    for(int i = 0;i < top;i += 1)
                    {
                        data[i] = rhs.data[i];
                    }
                }
                return *this;                
            }

            ~Stack() 
            {
                delete[] data;
            }

            void Push(const T& value)
            {
                if(top == capacity)
                {
                    Resize(2 * capacity);
                }
                data[top] = value;
                top += 1;
            }

            void Pop()
            {
                if(top != 0)
                {
                    top -= 1;
                }
            }

            const T& Top() const
            {
                if(top == 0)
                {
                    throw "Empty Stack";
                }
                return data[top-1];
            }

            bool IsEmpty() const
            {
                return (top == 0);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(top != 0)
                {
                    out << data[top-1];
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class T>
        class Stack : public StackInterface<T> 
        {
        private:
            Node<T>* top;

        public:
            Stack() : top(NULL) {}

            Stack(const Stack<T>& obj)
            {
                top = Copy(obj.top);
            }

            Stack<T>& operator=(const Stack<T>& rhs)
            {
                if(this != &rhs)
                {
                    Clear(top);
                    top = Copy(rhs.top);
                }
                return *this;                
            }

            ~Stack() 
            {
                Clear(top);
                top = NULL;
            }

            void Push(const T& value)
            {
                if(top == NULL)
                {
                    top = new Node<T>(value);
                }
                else
                {
                    Node<T>* tmp = new Node<T>(value);
                    tmp->SetLink(top);
                    top = tmp;
                }
            }

            void Pop()
            {
                if(top != NULL)
                {
                    Node<T>* tmp = top;
                    top = top->GetLink();
                    delete tmp;
                    tmp = NULL;
                }
            }

            bool IsEmpty() const
            {
                return (top == NULL);
            }

            const T& Top() const 
            {
                if(top == NULL)
                {
                    throw "Empty Stack";
                }
                return top->GetData();
            }
            
            std::string ToString() const 
            {
                std::stringstream out;

                if(top != NULL)
                {
                    out << top->GetData();
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}

#endif