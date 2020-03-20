#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

namespace ds 
{
    template <class T>
    class QueueInterface 
    {
    public:
        virtual void Enqueue(const T&) = 0;
        virtual void Dequeue() = 0;
        virtual const T& Peek() const = 0;
        virtual bool IsEmpty() const = 0;
    };

    namespace da
    {
        template <class T>
        class Queue : public QueueInterface<T> 
        {
        private:
            T* data;
            int capacity;
            int front;
            int back;

            void Resize(int ncp)
            {
                if(ncp <= 0)
                {
                    ncp = capacity * 2;
                }

                int tcp = (capacity < ncp)?(capacity):(ncp);
                T* tmp = new T[tcp];

                for(int i = 0;i < tcp - 1;i += 1)
                {
                    tmp[i] = data[(front + i) % capacity];
                }

                front = 0;
                back = capacity - 1;
                capacity = ncp;
                delete[] data;
                data = new T[capacity];

                for(int i = 0;i < tcp - 1;i += 1)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }

        public:
            Queue() : Queue(30) {}

            Queue(int capacity) : capacity(capacity), front(0), back(0)
            {
                if(this->capacity <= 1)
                {
                    this->capacity = 30;
                }

                data = new T[this->capacity];
            }

            Queue(const Queue<T>& obj)
            {
                front = obj.front;
                back = obj.back;
                capacity = obj.capacity;
                data = new T[capacity];

    			for(int i = front;i != back;i = (i + 1) % capacity)
	    		{
		    		data[i] = obj.data[i];
			    }
            }

            Queue<T>& operator=(const Queue<T>& rhs)
		    {
			    if(this != &rhs)
			    {
				    front = rhs.front;
				    back = rhs.back;
				    capacity = rhs.capacity;
				    delete[] data;
				    data = new T[capacity];
			
				    for(int i = front;i != back;i = (i + 1) % capacity)
				    {
					    data[i] = rhs.data[i];
				    }
			    }
			    return *this;
		    }

            ~Queue() 
            {
                delete[] data;
            }

            void Enqueue(const T& value)
            {
                if((back + 1) % capacity == front)
                {
                    Resize(2 * capacity);
                }
                data[back] = value;
                back = (back + 1) % capacity;
            }

            void Dequeue()
            {
                if(front != back)
                {
                    front = (front + 1) % capacity;
                }
            }

            const T& Peek() const
            {
                if(front == back)
                {
                    throw "Empty Queue";
                }
                return data[front];
            }

            bool IsEmpty() const
            {
                return (front == back);
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(front != back)
                {
                    out << data[front];
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }

    namespace sn
    {
        template <class T>
        class Queue : public QueueInterface<T> 
        {
        private:
            Node<T>* front;
            Node<T>* back;

        public:
            Queue() : front(NULL), back(NULL) {}

            Queue(const Queue<T>& obj)
            {
                front = Copy(obj.front);
                back = front;

                while(back->GetLink() != NULL)
                {
                    back = back->GetLink();
                }
            }

            Queue<T>& operator=(const Queue<T>& rhs)
            {
                if(this != &rhs)
                {
                    Clear(front);
                    front = Copy(rhs.front);
                    back = front;

                    while(back->GetLink() != NULL)
                    {
                        back = back->GetLink();
                    }
                }
                return *this;                
            }

            ~Queue() 
            {
                Clear(front);
                front = NULL;
                back = NULL;
            }

            void Enqueue(const T& value)
            {
                if(back == NULL)
                {
                    back = new Node<T>(value);
                    front = back;
                }
                else
                {
                    back->SetLink(new Node<T>(value));
                    back = back->GetLink();
                }
            }

            void Dequeue()
            {
                if(front != NULL)
                {
                    if(front == back)
                    {
                        delete front;
                        front = NULL;
                        back = NULL;
                    }
                    else
                    {
                        Node<T>* tmp = front;
                        front = front->GetLink();
                        delete tmp;
                        tmp = NULL;
                    }
                }
            }

            bool IsEmpty() const
            {
                return (front == NULL);
            }

            const T& Peek() const 
            {
                if(front == NULL)
                {
                    throw "Empty Queue";
                }
                return front->GetData();
            }

            std::string ToString() const 
            {
                std::stringstream out;

                if(front != NULL)
                {
                    out << front->GetData();
                }
                else
                {
                    out << "";
                }
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}

#endif