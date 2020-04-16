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
}

#endif