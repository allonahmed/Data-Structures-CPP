#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

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
            int size;
            int capacity;

            void Resize()
            {
                int ocp = capacity;
                capacity *= 2;
                T* tmp = new T[ocp];

                for(int i = 0;i < ocp;i += 1)
                {
                    tmp[i] = data[i];
                }
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < ocp;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }
        public:
            Stack() : size(0), capacity(50)
            {
                data = new T[capacity];
            }

            Stack(const Stack<T>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
                data = new T[capacity];

                for(int i = 0;i < size;i += 1)
                {
                    data[i] = obj.data[i];
                }
            }

            Stack<T>& operator=(const Stack<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    capacity = rhs.capacity;
                    delete[] data;
                    data = new T[capacity];

                    for(int i = 0;i < size;i += 1)
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
                if(size == capacity)
                {
                    Resize();
                }
                data[size] = value;
                size += 1;
            }

            void Pop()
            {
                if(size > 0)
                {
                    size -= 1;
                }
            }

            const T& Top() const 
            {
                if(size == 0)
                {
                    throw "Empty Stack";
                }
                return data[size-1];
            }

            bool IsEmpty() const 
            {
                return (size == 0);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(size > 0)
                {
                    out << data[size-1];
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

            const T& Top() const 
            {
                if(top == NULL)
                {
                    throw "Empty Stack";
                }
                return top->GetData();
            }

            bool IsEmpty() const 
            {
                return (top == NULL);
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

    namespace dn
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
                    top->SetPrev(new Node<T>(value));
                    top->GetPrev()->SetNext(top);
                    top = top->GetPrev();
                }
            }

            void Pop()
            {
                if(top != NULL)
                {
                    Node<T>* tmp = top;
                    top = top->GetNext();
                    delete tmp;
                    tmp = NULL;

                    if(top != NULL)
                    {
                        top->SetPrev(NULL);
                    }
                }
            }

            const T& Top() const 
            {
                if(top == NULL)
                {
                    throw "Empty Stack";
                }
                return top->GetData();
            }

            bool IsEmpty() const 
            {
                return (top == NULL);
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