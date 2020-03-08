#ifndef GTUSET_H
#define GTUSET_H

#include <stdexcept>
#include <vector>
#include "GTUContainer.h"

using namespace std;
namespace GTU{
    template <class T>
    class GTUSet:public GTUContainer<T>{
    public:
        GTUSet();
        bool empty() override;
        int size() override;
        int max_size() override ;
        void insert(T element) override;
        void erase(T element) override;
        void clear() override;
        GTUIterator<T>  begin() const override;
        GTUIterator<T> end() const override;
    protected:
        shared_ptr<T> SetArray;
        int Capacity = 10;
        int ArrSize = 0;
    };

}

#endif