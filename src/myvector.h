#ifndef INCLUDED_VECTOR_H
#define INCLUDED_MYVECTOR_H

#include <cstddef>

namespace mystd{

   template <class T>
    class myvector{

        T* array;

        size_t c, s;

        public:

            myvector();
            
            myvector(const myvector<T> &);

            void operator=(const myvector<T>&);
            
            ~myvector();

            void push_back(T);

            void pop_back();

            T front();

            T back();

            size_t size() const ;

            size_t capacity();

            void resize(size_t);

            void reserve(size_t);
             
    }; 
    template class myvector<int>;
};

#endif

