#ifndef INCLUDED_MYVECTOR_H
#define INCLUDED_MYVECTOR_H
#endif

#include <cstddef>
#include <initializer_list>

namespace mystd{

   template <class T>
    class myvector{

        T* array;

        size_t c, s;

        public:

            myvector();
            
            myvector(size_t s, T def = T() );
            
            myvector(std::initializer_list<T>);

            myvector(const myvector<T> &);

            void operator=(const myvector<T>&);
            
            T& operator[](const int& index);

            ~myvector();

            void push_back(T);

            void pop_back();

            T front();

            T back();

            size_t size() const ;

            size_t capacity();

            void resize(size_t, T def = T());

            void reserve(size_t);
             
    }; 
    template class myvector<int>;
};

