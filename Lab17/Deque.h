#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

namespace ds
{
    template <class T>
    class DequeInterface
    {
    public:
        virtual void InsertFirst(const T&) = 0;
        virtual void InsertLast(const T&) = 0;
        virtual void RemoveFirst() = 0;
        virtual void RemoveLast() = 0;
        virtual const T& First() const = 0;
        virtual T& First() = 0;
        virtual const T& Last() const = 0;
        virtual T& Last() = 0;
        virtual bool IsEmpty() const = 0;
        virtual int Size() const = 0;
    };

    namespace dn
    {
        template <class T>
        class Deque : public DequeInterface<T>
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;
        public:
            Deque() : head(NULL), tail(NULL), size(0) {}

            Deque(const Deque<T>& obj)
            {
                head = Copy(obj.head);
                tail = head;

                while(tail->GetLink() != NULL)
                {
                    tail = tail->GetLink();
                }
            }

            Deque<T>& operator=(const Deque<T>& rhs)
		    {
                if(this != &rhs)
                {
                    Clear(head);
                    head = Copy(rhs.head);
                    tail = head;

                    while(tail->GetLink() != NULL)
                    {
                        tail = tail->GetLink();
                    }
                }
                return *this;                
		    }

            ~Deque() 
            {
                Clear(head);
                head = NULL;
                tail = NULL;
            }

            void InsertFirst(const T& value)
            {
                 if(head==NULL)
                 {
                     head = new Node<T>(value);
                     tail = head;
                 }
                 else
                 {
                     Node<T>* tmp = new Node<T>(value);
                     tmp->SetNext(head);
                     head->SetPrev(tmp);
                     head = tmp;
                 }
                 size+=1;
            }

            void InsertLast(const T& value)
            {
                 if(tail==NULL)
                 {
                     head = new Node<T>(value);
                     tail = head;
                 }
                 else
                 {
                     Node<T>* tmp = new Node<T>(value);
                     tmp->SetPrev(tail);
                     tail->SetNext(tmp);
                     tail = tmp;
                 }
                 size +=1;
            }

            void RemoveFirst()
            {
                if(head!=NULL)
                {
                    if(head==tail)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                    }
                    else{
                        Node<T>* tmp = head;
                        head = head->GetNext();
                        delete tmp;
                        tmp = NULL;
                    }
                    size = size -1;
                }
            }

            void RemoveLast()
            {
                if(tail!=NULL)
                {
                    if(head==tail)
                    {
                        delete tail;
                        tail = NULL;
                        head = NULL;
                    }
                    else{
                        Node<T>* tmp = tail;
                        tmp = tmp->GetPrev();
                        delete tail;
                        tail = tmp;
                    }
                    size-=1;
                }
            }

            const T& First() const 
            {
                if(head == NULL)
                {
                    throw "Empty Deque";
                }
                return head->GetData();
            }   

            T& First() 
            {
                if(head == NULL)
                {
                    throw "Empty Deque";
                }
                return head->GetData();
            }

            const T& Last() const 
            {
                if(tail == NULL)
                {
                    throw "Empty Deque";
                }
                return tail->GetData();
            }   

            T& Last() 
            {
                if(tail == NULL)
                {
                    throw "Empty Deque";
                }
                return tail->GetData();
            }   

            bool IsEmpty() const
            {
                return (head == NULL);
            }

            int Size() const 
            {
                return size;
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(size > 0)
                {
                    out << head->GetData() << ":" << tail->GetData();
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Deque<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}
#endif