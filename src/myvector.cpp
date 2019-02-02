#include <myvector.h>
#include <algorithm>

namespace mystd{
    
    template <class T>
    myvector<T>::myvector(){
        s=0;
        c=0;
    }

    template <class T>
    myvector<T>::~myvector(){
        if(s > 0){
            delete [] array;
        }
    }

    template <class T>
    size_t myvector<T>::size(){
        return s;
    }
    
    template <class T>
    size_t myvector<T>::capacity(){
        return c;
    }

    template <class T>
    void myvector<T>::push_back(T val){
        if(s==c){
            resize((size_t)2*s);
        }
        array[s++] = val;
    }

    template <class T>
    void myvector<T>::pop_back(){
        s = s-1;
        if(s <= c/2){
            resize(s);
        }
    }

    template <class T>
    void myvector<T>::resize(size_t newSize){
        if(newSize > c){
            reserve(c*2);
        }
        else if (newSize > s){
            T val;
            while(s<newSize){
                array.push_back(val);
            }
        }
        else{
             while(s>newSize){
                array.pop_back(val);
            }
        }
    }

    template <class T>
    void myvector<T>::reserve(size_t newCapacity){
        if(newCapacity <=c){
            return;
        }
        T* old = array;
        array = new int[newCapacity];
        for(int i=0;i<s;i++){
            array[i] = old[i];
        }
        c = newCapacity;
        delete[] old;
    }

    template <class T>
    T myvector<T>::back(){
        return array[s-1];
    }

    template <class T>
    T myvector<T>::front(){
        return array[0];
    }

};