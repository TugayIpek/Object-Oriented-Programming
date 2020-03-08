#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include <iostream>
#include <cstdio>
#include <memory>
#include "GTUIterator.h"

using namespace std;
namespace GTU{

    template <class T>
    class GTUContainer{

    public:
        virtual bool empty()=0;
        virtual int size()=0;
        virtual int max_size()=0;
        virtual void insert(T)=0;
        virtual void erase(T)=0;
        virtual void clear()=0;
        virtual  GTUIterator<T>  begin() const =0 ;
        virtual  GTUIterator<T>  end() const =0 ;
    };
}

#endif