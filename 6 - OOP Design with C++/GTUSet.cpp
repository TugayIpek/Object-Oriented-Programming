#include "GTUSet.h"

namespace GTU{

    template <class T>
    GTUSet<T>::GTUSet(){

        shared_ptr<T> temp(new T[10], default_delete<T[]>());
        SetArray=temp;
        Capacity=10;
    }

    template <class T>
    bool GTUSet<T>::empty() {

        if(ArrSize==0)
            return true;
        else
            return false;
    };

    template <class T>
    int GTUSet<T>::max_size()  {
        return Capacity;
    };

    template <class T>
    void GTUSet<T>::insert(T element) {

        SetArray.get()[ArrSize]=element;
        ArrSize++;

        if(ArrSize==Capacity){
            T* temp=new T[ArrSize];
            for (int i =0;i<ArrSize;i++){

                temp[i]=SetArray.get()[i];
            }
            shared_ptr<T> shareTemp (new T[ArrSize*2], default_delete<T[]>());
            SetArray=shareTemp;
            for (int i=0;i<ArrSize;i++){
                SetArray.get()[i]=temp[i];
            }
            delete [] temp;
            Capacity=ArrSize*2;
        }
    }

    template <class T>
    void GTUSet<T>::erase(T element)  {
        shared_ptr<T> temp(new T[ArrSize], default_delete<T[]>());
        int count=0;
        for(int i=0;i<ArrSize;i++){

            if(!(SetArray.get()[i]==element)){
                temp.get()[count]=SetArray.get()[i];
                count++;
            }


        }
        SetArray.reset();
        SetArray=temp;
        ArrSize=count;

    }

    template <class T>
    void GTUSet<T>::clear()  {
        SetArray.reset();
        ArrSize=0;
        GTUSet();
    }

    template <class T>
    GTUIterator<T>  GTUSet<T>::begin() const  {
        GTUIterator<T> temp;
        temp.setCursor(&(SetArray.get()[0]));

        return temp;
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::end() const  {
        GTUIterator<T> temp;
        temp.setCursor(&(SetArray.get()[ArrSize-1]));

        return temp;
    };

    template <class T>
    int GTUSet<T>::size() {
        return ArrSize;
    };
}