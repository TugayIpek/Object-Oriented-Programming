#ifndef GTUITERATOR_H
#define GTUITERATOR_H
namespace GTU{
    
    template <class T>
    class GTUIterator{
    public:
        T& operator *()  ;

        bool operator==(const GTUIterator &other) const ;
        GTUIterator<T>& operator++();
        GTUIterator<T> operator++(int);
        bool operator!=(const GTUIterator &other) const ;
        T *getCursor() const ;
        void setCursor(T *cursor) ;
        GTUIterator<T>& operator=(const GTUIterator<T>& other);
        GTUIterator<T> * operator->();
    protected:
        T* cursor;
    };
}

#endif