#ifndef ITERATOR_H
#define ITERATOR_H

namespace ds
{
    template <class T>
    class IteratorInterface
    {
    public:
        virtual bool HasNext() const = 0;
        virtual T& Next() = 0;
    };

    namespace it
    {
        template<class T>
        class Iterator : public IteratorInterface<T> 
        {
        private:
            T* data;
            int cnt;
            int capacity;
        public:
            Iterator() : Iterator(NULL,0) {}

            Iterator(T* data,int capacity) : data(data), capacity(capacity), cnt(0) 
            {
                if(this->capacity < 0)
                {
                    this->capacity = 0;
                }
            }

            bool HasNext() const 
            {
                return (cnt < capacity);
            }

            T& Next() 
            {
                int c = cnt;
                cnt += 1;
                return data[c];
            }
        };
    }
}

#endif