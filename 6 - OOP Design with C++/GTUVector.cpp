#include "GTUVector.h"
namespace GTU{

    template <class T>
    GTUVector<T>::GTUVector(){

        shared_ptr<T> temp(new T[10], default_delete<T[]>());
        SetVector=temp;
        Capacity=10;
    }

    template <class T>
    bool GTUVector<T>::empty() {

        if(ArrSize==0)
            return true;
        else
            return false;
    };

    template <class T>
    int GTUVector<T>::max_size()  {
        return Capacity;
    };

    template <class T>
    void GTUVector<T>::insert(T element) {

        SetVector.get()[ArrSize]=element;
        ArrSize++;

        if(ArrSize==Capacity){
            T* temp=new T[ArrSize];
            for (int i =0;i<ArrSize;i++){

                temp[i]=SetVector.get()[i];
            }
            shared_ptr<T> shareTemp (new T[ArrSize*2], default_delete<T[]>());
            SetVector=shareTemp;
            for (int i=0;i<ArrSize;i++){
                SetVector.get()[i]=temp[i];
            }
            delete [] temp;
            Capacity=ArrSize*2;
        }
    }

    template <class T>
    void GTUVector<T>::erase(T element)  {
        shared_ptr<T> temp(new T[ArrSize], default_delete<T[]>());
        int count=0;
        for(int i=0;i<ArrSize;i++){

            if(!(SetVector.get()[i]==element)){
                temp.get()[count]=SetVector.get()[i];
                count++;
            }


        }
        SetVector.reset();
        SetVector=temp;
        ArrSize=count;

    }

    template <class T>
    void GTUVector<T>::clear()  {
        SetVector.reset();
        ArrSize=0;
        GTUVector();
    }

    template <class T>
    GTUIterator<T>  GTUVector<T>::begin() const  {
        GTUIterator<T> temp;
        temp.setCursor(&(SetVector.get()[0]));

        return temp;
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::end() const  {
        GTUIterator<T> temp;
        temp.setCursor(&(SetVector.get()[ArrSize-1]));

        return temp;
    };

    template <class T>
    int GTUVector<T>::size() {
        return ArrSize;
    };
}