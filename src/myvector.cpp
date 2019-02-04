#include <myvector.h>
#include <algorithm>

namespace mystd{
    
    template <class T>
    myvector<T>::myvector(){
        s=0;
        c=0;
    }

    template <class T>
    myvector<T>::myvector(size_t newSize, T def){
       s=0;
       c=0;
       resize(newSize, def);
    }

    template <class T>
    myvector<T>::myvector(std::initializer_list<T> iList){
        s=0;
        c=0;
        reserve(iList.size());
        for(auto it=iList.begin();it!=iList.end();++it){
            push_back(*it);
        }
    }
    
    template <class T>
    myvector<T>::myvector(const myvector<T>& other){
        s=0;
        c=0;
        reserve(other.size());
        for(size_t i=0;i<other.size();i++){
            push_back(other.array[i]);
        }
    }

    template <class T>
    void myvector<T>::operator=(const myvector<T>& other){
        reserve(other.size());
        for(int i=0;i<other.size();i++){
            push_back(other.array[i]);
        }
    }


    template <class T>
    T& myvector<T>::operator[](const int& index){
        return array[index];
    }


    template <class T>
    myvector<T>::~myvector(){
        if(s > 0){
            delete [] array;
        }
    }

    template <class T>
    size_t myvector<T>::size() const {
        return s;
    }
    
    template <class T>
    size_t myvector<T>::capacity(){
        return c;
    }

    template <class T>
    void myvector<T>::push_back(T val){
        if(s==c){
            reserve((size_t)2*(c+1));
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
    void myvector<T>::resize(size_t newSize, T def){
        if(newSize < s){
            while(s>newSize){
                pop_back();
            }
        }
        else{
            if(newSize > c){
                reserve((c+1)*2);
            }
            while(s<newSize){
                push_back(def);
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
        if(s > 0)
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