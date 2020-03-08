#include "GTUIterator.h"
namespace GTU{

    template <class T>
    T& GTUIterator<T>::operator *()  
    {
        return *cursor;
    }

    template <class T>
    bool GTUIterator<T>::operator==(const GTUIterator &other) const 
    {
        return cursor == other.cursor;
    }

    template <class T>
    GTUIterator<T>& GTUIterator<T>:: operator++()
    {
        this->cursor=cursor+1;
        return *this;
    }

    template <class T>
    GTUIterator<T> GTUIterator<T>::operator++(int)
    {
        GTUIterator<T> tmp  =*this;
        this->cursor=cursor+1;
        return tmp;
    }

    template <class T>
    bool GTUIterator<T>::operator!=(const GTUIterator &other) const 
    {
        return !(other == *this);
    }

    template <class T>
    T* GTUIterator<T>:: getCursor() const 
    {
        return cursor;
    }

    template <class T>
    void GTUIterator<T>:: setCursor(T *cursor) 
    {
        GTUIterator::cursor = cursor;
    }

    template <class T>
    GTUIterator<T>& GTUIterator<T>:: operator=(const GTUIterator<T>& other)
    {
        if (this == &other){
            return *this;
        }
        this->cursor =other.cursor;
        return *this;
    }

    template <class T>
    GTUIterator<T>* GTUIterator<T>:: operator->()
    {

        return this;
    }
}